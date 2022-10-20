#pragma once

#include <string>
#include <iostream>

class WorkerBuilder;

class Worker {

    std::string requestorName;

    public:
        bool isProgrameable;
        bool isWorkable;
        bool isStrong;
        double cost;

        Worker(std::string requestorName) : requestorName (requestorName) {}

        friend WorkerBuilder;
        static WorkerBuilder create(std::string requestorName);
};

class WorkerBuilder {

    Worker worker;

    public:
        WorkerBuilder(std::string requestorName) : worker(requestorName) {}

        // conver WorkerBuilder to Worker
        operator Worker() const { return std::move(worker); }

        WorkerBuilder& trainToProgram();
        WorkerBuilder& trainToWork();
        WorkerBuilder& workout();
        WorkerBuilder& addCost(double const cost);
};