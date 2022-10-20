#include "Builder.h"

WorkerBuilder Worker::create(std::string requestorName) 
{
    return WorkerBuilder(requestorName);
}

WorkerBuilder& WorkerBuilder::trainToProgram() 
{
    worker.isProgrameable = true;
    return *this;
}

WorkerBuilder& WorkerBuilder::trainToWork()
{
    worker.isWorkable = true;
    return *this;
}
WorkerBuilder& WorkerBuilder::workout() 
{
    worker.isStrong = true;
    return *this;
}

WorkerBuilder& WorkerBuilder::addCost(double const cost)
{
    worker.cost = cost;
    return *this;
}

int main() 
{
    Worker workerA = Worker::create("CreatorA")
                        .trainToProgram()
                        .addCost(2000.00);
    Worker workerB = Worker::create("CreatorB")
                        .workout()
                        .trainToWork()
                        .addCost(20.00);

    std::cout<<workerA.cost<<std::endl;
    std::cout<<workerB.cost<<std::endl;
}