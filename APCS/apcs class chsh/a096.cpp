# include <bits/stdc++.h>
using namespace std;

int sti(char str){
    return str - '0'; // '0' - '9' = 0 - 9
}

void on(int n){
    if (n<10){
        cout << "0" << n;
    }
    else{
        cout << n;
    }
}



int main(){
    int time_first[3] = { };
    int time_last[3] = { };
    int time_diff[3] = { };
    string time;
    cin >> time;
    //cout << time << endl;
    time_first[0] = sti(time[0])*10+sti(time[1]);
    time_first[1] = sti(time[3])*10+sti(time[4]);
    time_first[2] = sti(time[6])*10+sti(time[7]);
    cin >> time;
    time_last[0] = sti(time[0])*10+sti(time[1]);
    time_last[1] = sti(time[3])*10+sti(time[4]);
    time_last[2] = sti(time[6])*10+sti(time[7]);
    //cout << time << endl;
    if(time_last[2]>=time_first[2]){
        time_diff[2] += (time_last[2] - time_first[2]);
    }
    else{
        time_diff[2] += (time_last[2] + 60 - time_first[2]);
        time_diff[1]--;
    }

    if(time_last[1]>=time_first[1]){
        time_diff[1] += (time_last[1] - time_first[1]);
    }
    else{
        time_diff[1] += (time_last[1] + 60 - time_first[1]);
        time_diff[0]--;
    }

    if(time_last[0]>=time_first[0]){
        time_diff[0] += (time_last[0] - time_first[0]);
    }
    else{
        time_diff[0] += (time_last[0] + 24 - time_first[0]);
    }
    on(time_diff[0]);
    cout << ":";
    on(time_diff[1]);
    cout << ":";
    on(time_diff[2]);
}