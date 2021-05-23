#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start_time, duration, end_time;
};

struct Available_Workshops
{
    int n;
    vector<Workshop> workshop;
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops* aw = new Available_Workshops();
    aw->n = n;

    for (int i = 0; i < n; i++)
    {
        Workshop ws;
        ws.start_time = start_time[i];
        ws.duration = duration[i];
        ws.end_time = start_time[i] + duration[i];
        //aw->workshop[i] = ws;
        aw->workshop.push_back(ws);
    }
    return aw;
}

bool compare_workshop(const Workshop& w1, const Workshop& w2)
{
    return w1.end_time - w2.end_time > 0;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int max = 0;
    vector<Workshop> vec_ws = ptr->workshop;
    sort(vec_ws.begin(), vec_ws.end(), compare_workshop);
    while (vec_ws.size())
    {
        ++max;
        int end_time = vec_ws.back().end_time;
        bool overlap = true;
        while (vec_ws.size() && overlap)
        {
            vec_ws.pop_back();
            if (vec_ws.back().start_time >= end_time)
                overlap = false;
        }
    }
    return max;
}

int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
