#ifndef CONTROLABLETHREAD_H_INCLUDED
#define CONTROLABLETHREAD_H_INCLUDED

class ControlableThread{
public:
    static vector<boost::thread*> threads;


    void start();
    void stop();
    void pause();
    void pause_for();
    void resume();

};

#endif // CONTROLABLETHREAD_H_INCLUDED
