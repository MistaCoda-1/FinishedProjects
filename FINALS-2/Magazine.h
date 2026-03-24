#pragma once
using namespace std;

class Magazine : public Book {
    private:
        string topic;
        int issueNumber;
    public:
        Magazine() : Book() {
            topic = "";
            issueNumber = 0;
        }

        Magazine(string bTitle, string bAuthor, bool bAvail, string bTopic, int issueNo) :
            Book("Magazine", bTitle, bAuthor, bAvail),
            topic(bTopic),
            issueNumber(issueNo)
        { }
        
        void showInformation() const override {
            cout << getType() << " Book\n"
                 << "Title: " << getTitle() << " | "
                 << "Author: " << getAuthor() << " | "
                 << "Topic: " << topic << " | "
                 << "Issue Number: " << issueNumber << " | ";

            cout << (isAvailable() ? "[AVAILABLE]" : "[BORROWED]");

            cout << "\n";
        }
        
        void saveInformation(ofstream& out) const override {    // Writes to a file in a specific format for loading later on.
            out << "Magazine|"
                << getTitle() << "|"
                << getAuthor() << "|"
                << isAvailable() << "|"
                << topic << "|"
                << issueNumber << "\n";

            // Sample format:
            // Magazine|Title|Author|0/1|Topic|Issue Number
        }

        string getTopic() { return topic; }
        int getIssueNo() { return issueNumber; }
};