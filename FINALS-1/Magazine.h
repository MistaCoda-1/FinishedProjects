#pragma once
using namespace std;

class Magazine : public Book {      // Derived class of Book : Magazines
    private:
        int issueNo;
        string topic;
    public:
        Magazine() : Book() {
            issueNo = 0;
            topic = "";
        }
        Magazine(string t, string a, int p, bool b, int issNo, string magTopic) : 
            Book(t, a, p, b),   // Initiate base class before anything else
            issueNo(issNo),
            topic(magTopic)
        { }

        void showInformation(int i) const override {
            cout << "Magazine - Book #" << i << "\n";

            cout << "Issue Number: " << issueNo << " | "
                 << "Topic: " << topic << "\n";

            cout << "Title: " << getTitle() << " | "
                << "Author: " << getAuthor() << " | "
                << "Book Pages: " << getPageAmount() << " | ";

                isAvail();

            cout << "\n";
            cout << "| - - - - - - - - - - - - - - - - - |\n";
        }

        // Getter functions
        int getIssueNo() const { return issueNo; }
        string getTopic() const { return topic; }
};