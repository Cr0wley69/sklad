#pragma once
#include<iostream>
#include<vector>
//���� ��� ������ ��������� time ������������ ���, ����� ��� ����� ������� ������������ ���� ���
class Trucks
{
public:
    int getCapacity();
    int getDeliveryTime();
    std::vector<int>* getTime();
    void setCapacity(int capacity);
    void setDeliveryTime(int delivery_time);
    void addTime(int time);
    bool isBusy(int time);
private:
    std::vector<int> _time;
    int _capacity, _delivery_time;
};

