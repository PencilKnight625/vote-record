#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Candidate 
{
    string name;
    int votes = 0;
};

void showCandidates(const vector<Candidate>& candidates) 
{
    cout << "\n️ Candidates List:\n";
    for (size_t i = 0; i < candidates.size(); ++i) 
    {
        cout << i + 1 << ". " << candidates[i].name << "\n";
    }
}

void vote(vector<Candidate>& candidates) 
{
    int choice;
    showCandidates(candidates);
    cout << "\nEnter the number of the candidate you want to vote for: ";
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > (int)candidates.size()) 
    {
        cout << "Invalid choice. Vote not counted.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    candidates[choice - 1].votes++;
    cout << "Vote recorded for " << candidates[choice - 1].name << "!\n";
}

void showResults(const vector<Candidate>& candidates) 
{
    cout << "\n Voting Results:\n";
    for (const auto& candidate : candidates) 
    {
        cout << candidate.name << ": " << candidate.votes << " vote(s)\n";
    }
}

void showWinner(const vector<Candidate>& candidates) 
{
    int maxVotes = 0;
    for (const auto& c : candidates) 
    {
        if (c.votes > maxVotes) 
        {
            maxVotes = c.votes;
        }
    }
    if (maxVotes == 0) 
    {
        cout << "No votes were cast.\n";
        return;
    }
    cout << "\n Winner(s):\n";
    for (const auto& c : candidates) 
    {
        if (c.votes == maxVotes) 
        {
            cout << c.name << " with " << c.votes << " vote(s)\n";
        }
    }
}

int main() 
{
    vector<Candidate> candidates;
    int numCandidates;

    cout << "==== Welcome to the Voting System ====\n";
    cout << "Enter number of candidates: ";
    cin >> numCandidates;

    if (numCandidates <= 0) 
    {
        cout << "Invalid number of candidates.\n";
        return 1;
    }

    cin.ignore(); // clear newline character from input buffer
    for (int i = 0; i < numCandidates; ++i) 
    {
        Candidate c;
        cout << "Enter name for candidate " << (i + 1) << ": ";
        getline(cin, c.name);
        candidates.push_back(c);
    }

    int choice;
    do 
    {
        cout << "\n===== VOTING MENU =====\n";
        cout << "1. Cast Vote\n";
        cout << "2. Show Results\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                vote(candidates);
                break;
            case 2:
                showResults(candidates);
                break;
            case 3:
                cout << " Exiting Voting System.\n";
                cout << "\nFinal Results:\n";
                showResults(candidates);
                showWinner(candidates);
                cout << "Thankyou for Using :) Goodbye!\n";
                break;
            default:
                cout << "Invalid option :( Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
