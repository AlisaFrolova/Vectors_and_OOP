#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
private:
    string name;
    string nickname;
    int age;
    string team;
    vector<int> points;
    int userID;

    static int nextID;

public:

    // delegated constructor 
    Player() : Player("None", "None", 0, "None") 
    {}

    // constructor with parameters without vector
    Player(const string& n,
        const string& nick,
        int a,
        const string& t)
        : name(n), nickname(nick), age(a), team(t), points()
    {
        userID = ++nextID;
        cout << "Object has been created" << ", ID = " << userID << endl;
    }

    // constructor with parameters with vector
    Player(const string& n,
        const string& nick,
        int a,
        const string& t,
        const vector<int>& pts)
        : name(n), nickname(nick), age(a), team(t), points(pts)
    {
        userID = ++nextID;
        cout << "Object has been created" << ", ID = " << userID << endl;
    }

    //static method
    static int getTotalUsers()
    {
        return nextID;
    }

    // getters / setters
    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void setNickname(const string& nick) { nickname = nick; }
    string getNickname() const { return nickname; }

    void setAge(int a) { if (a > 0 && a < 120) age = a; }
    int getAge() const { return age; }

    void setTeam(const string& t) { team = t; }
    string getTeam() const { return team; }

    void setMatches(int m) { points.resize(m); }
    int getMatches() const { return points.size(); }

    int getUserID() const { return userID; }

    // methods
    void printInfo() const
    {
        cout << "ID: " << userID << " | " << name << " | " << nickname << " | "
            << age << " | " << team << endl;
        printPoints();
    }

    void printPoints() const
    {
        if (points.empty())
        {
            cout << "No points\n";
            return;
        }
        cout << name << "'s points: ";
        for (int p : points) cout << p << " ";
        cout << endl;
    }

    void addPoint(int p) { points.push_back(p); }

    double countPoints() const
    {
        if (points.empty()) return 0.0;
        double sum = 0;
        for (int p : points) sum += p;
        return sum / points.size();
    }

    void clearPoints()
    {
        points.clear();
        cout << "Points cleared\n";
    }

    void setPoints()
    {
        if (points.empty()) return;
        cout << "Enter " << points.size() << " points for " << name << ": ";
        for (int& p : points) cin >> p;
    }
};

int Player::nextID = 0;//to initialize static field

int main()
{
    Player p1("Ivan", "Ivan121", 12, "Red");
    p1.setMatches(3);
    p1.setPoints();
    p1.printInfo();

    cout << "\n";

    vector<int> pts = { 10, 15, 8, 12 };
    Player p2("Alex", "Shadow", 17, "Blue", pts);
    p2.printInfo();
    cout << p2.countPoints() << " - average" << endl;

    cout << "\n";

    Player p3;
    p3.printInfo();

    cout << Player::getTotalUsers() << endl;

    return 0;
}
