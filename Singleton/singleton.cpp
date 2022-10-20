#include <iostream>

class Worker {
    
    int state;
    // private constructor
    Worker() {}

    public:
        // remove copy constructor
        Worker(Worker const&) = delete;

        // remove assignment operator
        Worker &operator=(Worker const&) = delete;

        static Worker &instance() 
        {
            static Worker instance;
            return instance;
        }

        int getState() 
        {
            return state;
        }

        void setState(int const state) 
        {
            this->state = state;
        }
};

int main () {
    // not allow
    // Worker test = Worker();

    // not allow
    // worker test = Worker::instance();

    Worker::instance().setState(100);

    std::cout<<Worker::instance().getState()<<std::endl;
}
