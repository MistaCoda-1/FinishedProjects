VERSION #2

To compile the program properly,
    Step 1 : Create a folder, anywhere.
    Step 2 : Compile/Put all the files (source file, headers, and savefile.txt) inside said folder.
    Step 3 : Right click an empty space in the file explorer, and click "Open in terminal"
    Step 4 : Once inside the terminal, type in "g++ *.cpp -o main" to compile.
    Step 5 : You should now have a "main.exe" file in your folder. Now type in the terminal "./main" or "main.exe" to run the file.

IN-DEPTH EXPLANATION FOR LOADING :

// START
    string line;
    while (getline(in, line)) {
        vector<string> tokens;
        size_t end;

        while ((end = line.find('|')) != string::npos) {
            tokens.push_back(line.substr(0, end));
            line.erase(0, end + 1);
        }
        
        tokens.push_back(line);

        string type = tokens[0];

        if (type == "Literature" && tokens.size() == 6) {
            string title = tokens[1];
            string author = tokens[2];
            bool available = (tokens[3] == "1");
            string genre = tokens[4];
            string language = tokens[5];

            Books.push_back(new Literature(title, author, available, genre, language));
        } else if (type == "Magazine" && tokens.size() == 6) {
            string title = tokens[1];
            string author = tokens[2];
            bool available = (tokens[3] == "1");
            string topic = tokens[4];
            int issueNo = stoi(tokens[5]);

            Books.push_back(new Magazine(title, author, available, topic, issueNo));
        } else {
            cout << "INVALID BOOK TYPE DETECTED!\n";
            return;
        }
    }
// END

`while (getline(in, line))`

Used to take the entire line/record of in the savefile.
Sample format: Literature|q|w|0|e|r

```
while ((end = line.find('|')) != string::npos) {
    tokens.push_back(line.substr(0, end));
    line.erase(0, end + 1);
}
```

Used to find '|' and takes everything before `end` not including `end` itself as a substring.

Basically it finds `|` in a record like : Literature|q|w|0|e|r
    and takes everything before the '|' as a `token` of data to use later.
    in the first iteration of the loop it will take "Literature" and erases it after
    storing that piece of data into the `tokens` vector. We erase the data so we don't keep taking
    the same piece of data over and over again.

`tokens.push_back(line);`

Used to push back the last piece of data at the end of the record since there'd be no more '|' to find
    we have to push it back manually.

`string type = tokens[0];`

Used to store the type of book for comparisons later.

```
if (type == "Literature" && tokens.size() == 6) {
    string title = tokens[1];
    string author = tokens[2];
    bool available = (tokens[3] == "1");
    string genre = tokens[4];
    string language = tokens[5];

    Books.push_back(new Literature(title, author, available, genre, language));
} else if (type == "Magazine" && tokens.size() == 6) {
    string title = tokens[1];
    string author = tokens[2];
    bool available = (tokens[3] == "1");
    string topic = tokens[4];
    int issueNo = stoi(tokens[5]);

    Books.push_back(new Magazine(title, author, available, topic, issueNo));
}
```

This uses the `type` variable we set before this snippet to determine what type of book
    the loading function needs to create. After determining what kind of book the record is
    we rebuild it using the `tokens` vector we filled up with the necessarry data needed to
    reconstruct the object and then finally pushing it into the library vector `Books`