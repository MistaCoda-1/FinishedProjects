#include<iostream>
#include<string>
using namespace std;

class Buckets {
private:

int waterLevels;
const int maxWater = 100;
bool full;

public:
Buckets() {
    waterLevels = 0;
    full = false;
}
Buckets(int x) {
    waterLevels = x;
    full = (waterLevels == maxWater);
}
void display(int i) {
    cout << "Bucket #" << i + 1 << " - " << waterLevels << " | units of water" << endl;
}
int raiseWaterLevel() {
    waterLevels += 10;
    return waterLevels;
}
void checkWaterLevel() {
    cout << "This bucket has " << waterLevels << " units of water!\n";
}
int getWaterLevel() {
    return waterLevels;
}
bool isFull() {
    return full;
}

};

class Bathroom {
private:

Buckets bucket[3] = {
    Buckets(50),
    Buckets(30),
    Buckets()
};
bool faucet;

public:

void showBuckets() {
    cout << "-----------------------------|\n";
    for (int i = 0; i < 3; i++) {
        bucket[i].display(i);
    }
    cout << "-----------------------------|\n";
}

void chooseBucket(int &bucketChoice) {
    cout << "Currently filling up Bucket #"
         << bucketChoice << endl;
    cout << "-----------------------------|\n";
}

void faucetControl() {
    char temp;
    cout << "Turn on faucet?(y/n): ";
    cin >> temp;

    if (temp == 'y' || temp == 'Y') {
        faucet = true;
        cout << "The water level of the bucket slowly rises . . .\n";
    } else {
        cout << "You stand there wondering why you didn't turn the faucet on . . .\n";
        faucet = false;
    }
}

bool allBucketsFilled() {
    int waterSum = 0;
    for (int i = 0; i < 3; i++) {
        waterSum += bucket[i].getWaterLevel();
    }
    return (waterSum != 300);
}

void passTime(int &bucketChoice) {
    cout << "5 minutes pass . . .\n";
    cout << "-----------------------------|\n";

    Buckets &currentBucket = bucket[bucketChoice - 1];
    if (faucet) {
        int waterUnits = currentBucket.raiseWaterLevel();
        cout << "Bucket #" << bucketChoice << " now has " << waterUnits
             << " Units of water" << endl;
        cout << "-----------------------------|\n";
    } else {
        cout << "You start to regret your own existence . . .\n";
        currentBucket.display(bucketChoice - 1);
        cout << "-----------------------------|\n";
    }
}

};

int main() {
    Bathroom bathroom;

    bool allFull;
    int chosenBucket;

    cout << "== Random everyday things in my life that I make into a program cause why not. ==\n\n";

    cout << "Bucket list:\n";
    bathroom.showBuckets();

    do {
        cout << "Which bucket to fill?: ";
        cin >> chosenBucket;

        bathroom.chooseBucket(chosenBucket);
        bathroom.faucetControl();
        bathroom.passTime(chosenBucket);

    } while (bathroom.allBucketsFilled());

    return 0;
}