/*Suppose there is a circle. There are N petrol pumps on that circle. Petrol pumps are numbered  0 to (N-1)  (both inclusive). You have two pieces of information corresponding to each of the petrol pump: 
(1) the amount of petrol that particular petrol pump will give, and 
(2) the distance from that petrol pump to the next petrol pump.*/

#include <iostream>
using namespace std;

int canCompleteCircuit(int petrol[], int distance[], int N) {
    int totalPetrol = 0, currentPetrol = 0, startIndex = 0;

    for (int i = 0; i < N; i++) {
        totalPetrol += petrol[i] - distance[i];
        currentPetrol += petrol[i] - distance[i];

        if (currentPetrol < 0) {
            startIndex = i + 1;  
            currentPetrol = 0;
        }
    }

    return (totalPetrol < 0) ? -1 : startIndex;
}

int main() {
    int N;
    cout << "Enter the number of petrol pumps: ";
    cin >> N;

    int petrol[N], distance[N];
    cout << "Enter the amount of petrol at each pump: ";
    for (int i = 0; i < N; i++) {
        cin >> petrol[i];
    }

    cout << "Enter the distance to the next pump from each pump: ";
    for (int i = 0; i < N; i++) {
        cin >> distance[i];
    }

    int result = canCompleteCircuit(petrol, distance, N);
    if (result == -1) {
        cout << "It is not possible to complete the circle." << endl;
    } else {
        cout << "The vehicle can complete the circle starting from pump " << result << endl;
    }

    return 0;
}
