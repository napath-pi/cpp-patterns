#include <iostream>
#include <string>
#include <vector>

class Worker {
    public:
        virtual Worker* clone() = 0;
        virtual void work() = 0;
        virtual ~Worker() { }
};

class EngineerWorker : public Worker {
    public:
        Worker* clone () 
        {
            return new EngineerWorker;
        } 

        void work()
        {
            std::cout<<"Engineer!!!"<<std::endl;
        }
};

class MarketingWorker : public Worker {
    public:
        Worker* clone () 
        {
            return new MarketingWorker;
        } 

        void work()
        {
            std::cout<<"Market!!!"<<std::endl;
        }
};

class ManagerWorker : public Worker {
    public:
        Worker* clone () 
        {
            return new ManagerWorker;
        } 

        void work()
        {
            std::cout<<"Manager!!!"<<std::endl;
        }
};

class WorkManager {
    public:
        static Worker* createWorker( int workerType);
        ~WorkManager() { }
    
    private:
        static Worker* workers[3];
};

Worker* WorkManager::workers[3] = {
    new EngineerWorker, new MarketingWorker, new ManagerWorker
};


Worker* WorkManager::createWorker( int workerType) {
    return WorkManager::workers[workerType]->clone();
}

int main() {

    std::vector<Worker*> arrmy;
    for( int i=0;i<10;i++) {
        arrmy.push_back(WorkManager::createWorker(rand()%3));
    }

    for(int i=0;i<arrmy.size();i++) {
        arrmy[i]->work();
    }

    for( int i=0;i<10;i++) {
        delete arrmy[i];
    }

}