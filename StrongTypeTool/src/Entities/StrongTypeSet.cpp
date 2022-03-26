//
// Created by waschbar on 10.02.22.
//

#include "StrongTypeSet.h"

#include <stack>
#include <algorithm>
#include <utility>

stt::StrongTypeSet::StrongTypeSet(std::vector<stt::StrongType> types, std::vector<stt::StrongLiteral> literals)
    : types(std::move(types)), literals(std::move(literals)) {

    for(stt::StrongType &type : this->types) {
        this->nameToType[type.getTypeName()] = &type;
    }

    for(stt::StrongLiteral &literal : this->literals) {
        this->literalsDependency.insert(literal.getResType());
    }

    this->buildDependencyGraph();
    this->resolveDependencies();
}

std::vector<stt::StrongType> stt::StrongTypeSet::getDependencies(const stt::StrongType& type) const {
    if(this->dependencyList.find(type.getTypeName()) == this->dependencyList.end())
        return {};
    return this->dependencyList.at(type.getTypeName());
}

void stt::StrongTypeSet::buildDependencyGraph() {
    for(stt::StrongType &type : this->types) {
        std::set<stt::StrongType*> usedTypes;

        for(const BinaryOperation& op : type.getBinaryOperations()) {
            auto it = this->nameToType.find(op.getArgType());
            if(it != this->nameToType.end())
                usedTypes.insert(it->second);

            it = this->nameToType.find(op.getResType());
            if(it != this->nameToType.end())
                usedTypes.insert(it->second);
        }

        for(const UnaryOperation& op : type.getUnaryOperations()) {
            auto it = this->nameToType.find(op.getResType());
            if(it != this->nameToType.end())
                usedTypes.insert(it->second);
        }

        for(stt::StrongType* usedType : usedTypes)
            this->dependencyGraph[&type].push_back(usedType);
    }
}

void topologyDFS(stt::StrongType* type, std::map<stt::StrongType*, std::vector<stt::StrongType*>> &graph,
                 std::map<stt::StrongType*, bool> &visited, std::vector<stt::StrongType*> &reverseTopology) {
    visited[type] = true;
    for(stt::StrongType* next : graph[type]) {
        if(!visited[next])
            topologyDFS(next, graph, visited, reverseTopology);
    }
    reverseTopology.push_back(type);
}

std::map<stt::StrongType*, int> getTopology(std::map<stt::StrongType*, std::vector<stt::StrongType*>> &graph) {
    std::map<stt::StrongType*, bool> visited;
    std::vector<stt::StrongType*> reverseTopology;

    for(const auto& it : graph) {
        if(!visited[it.first])
            topologyDFS(it.first, graph, visited, reverseTopology);
    }

    std::map<stt::StrongType*, int> topologyOrder;
    int order = 1;
    for(auto it = reverseTopology.rbegin(); it != reverseTopology.rend(); it++) {
        topologyOrder[*it] = order;
        order++;
    }

    return topologyOrder;
}

void DFS(stt::StrongType* node, std::map<stt::StrongType*, bool> &visited, std::map<stt::StrongType*, std::vector<stt::StrongType*>> &graph) {
    visited[node] = true;
    for(stt::StrongType* next : graph[node])
        if(!visited[next])
            DFS(next, visited, graph);
}

void stt::StrongTypeSet::resolveDependencies() {
    std::map<stt::StrongType*, int> order = getTopology(this->dependencyGraph);

    auto comparator = [&order](stt::StrongType* a, stt::StrongType* b) {
        return order[a] < order[b];
    };

    for(auto &it : this->dependencyGraph) {
        sort(it.second.begin(), it.second.end(), comparator);
    }

    std::set<stt::StrongType*, decltype(comparator)> nodes(comparator);
    for(const auto& it : this->dependencyGraph)
        nodes.insert(it.first);

    for(stt::StrongType* node : nodes) {

        std::map<stt::StrongType*, bool> visited;
        visited[node] = true;
        for(stt::StrongType* next : this->dependencyGraph[node]) {
            if(!visited[next]) {
                this->dependencyList[node->getTypeName()].push_back(*next);
                DFS(next, visited, this->dependencyGraph);
            }
        }
    }

}
