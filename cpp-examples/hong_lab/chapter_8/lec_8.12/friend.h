#pragma once

class A;


class B
{
private:
    int m_value;

public:
    B();
    void doSomething (A &a );

};

class A
{
private:
    int m_value;
    friend void B::doSomething(A &a);
public:
    A();
};

