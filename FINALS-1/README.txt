Brought to you by Dominic Muldez.

This is my Finals Project. I "MAYBE" went a little too far on this one
in terms of complexity.

This program consists of 4 classes; Book, Literature, Magazine, and Library.

These 4 Classes work together to create a mini library system where the user can:
    - Add a Book of their choice---Literature or Magazine.
    - Remove a specific Book in the Library.
    - View currently existing Books in the Library.
    - Borrow a Book from the library.
    - And subsequently return the Book.

To compile the program properly,
    Step 1 : Create a folder, anywhere.
    Step 2 : Compile/Put all the files (source file, headers, and savefile.txt) inside said folder.
    Step 3 : Right click an empty space in the file explorer, and click "Open in terminal"
    Step 4 : Once inside the terminal, type in "g++ *.cpp -o main" to compile.
    Step 5 : You should now have a "main.exe" file in your folder. Now type in the terminal "./main" to run the file.


Deep Dive into Save & Load function:
| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |

The main point of interest in this program is the saving and loading functions.
This was made a bit overly complex due to me wanting two derived classes for `Book`, which led me to creating a program that can
determine if an entry/record (inside the savefile) is a `Literature` class/object or `Magazine` class/object.

Code Snippet - Saving Function P1:
    for (Book* b : Books) {
        if (Literature* lit = dynamic_cast<Literature*>(b)) {
            out << "Literature|"
                << lit->getTitle() << "|"
                << lit->getAuthor() << "|"
                << lit->getPageAmount() << "|"
                << lit->borrowed() << "|"
                << lit->getGenre() << "|"
                << lit->getLanguage() << "\n";
        } 
        else if (Magazine* mag = dynamic_cast<Magazine*>(b)) {
            out << "Magazine|"
                << mag->getTitle() << "|"
                << mag->getAuthor() << "|"
                << mag->getPageAmount() << "|"
                << mag->borrowed() << "|"
                << mag->getIssueNo() << "|"
                << mag->getTopic() << "\n";
        }
    }
// END

    Important note before reading the explanation below is that in `Library` we have a vector of pointers
    `vector<Book*> Books`

    Explanation: Trust me, it's actually pretty simple once you know what `dynamic_cast` is.

    `for (Book* b : Books)` is ranged for loop, which basically loops through the vector of base class pointers in library
    and then uses dynamic_cast.

    `dynamic_cast` is a c++ operator that lets you determine if a base class pointer is pointed to a derived class AT RUNTIME.
    If it sees that the pointer in `Book* b` is pointed to a derived class in this case a Literature class, it returns a valid
    pointer, which can be interpreted as true. If not, it returns a nullptr which can be interpreted as false.

    Knowing that, we can easily check with two if statements which derived class it points to. If it's not this, then it's the other one.

    About the writing part, it's super simple, just get all the data with your getters and seperate them with whatever the hell you want lol
    sorry, it's currently 3:13 AM and I started working on this at 4PM...

    Continuing from that, you can put any separator you want really, just make sure you specify it in the load function so it knows which
    character to skip in the line/record 


Code Snippet - Loading Function P1:
    for (Book* b : Books) {
        delete b;
    }
    Books.clear();
// END

    Explanation: This block deletes every `Book` object inside the vector to prevent duplication when loading.

Code Snippet - Loading Function P2:
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        vector<string> tokens;

        // Split line by '|'
        while (getline(ss, token, '|')) {
            tokens.push_back(token);
        }
// END

    Explanation: This block I prepared all the necessarry variables to READ from the savefile, and insert it into the `Library`

    `stringstream ss(line)` is where the magic happens, this header lets me treat a "line" in this case it would be a record in the savefile
    as an input stream, ex: Magazine|Scientific American|Various|90|0|784|Science

    Since we can treat the "line/record" as a stream of inputs, I can do `getline(ss, token, '|')` which is basically: treat this as a cin
    which goes into the `token` variable, and separate each token when you detect '|'

    After the getline, the token is inserted into the `tokens` vector, which is now a collection of data we can input into the library vector.

Code Snippet - Loading Function P3:
    if (tokens.empty()) continue;
// END

    Explanation: This line simply skips an iteration/line if it couldn't read a line in the savefile.

Code Snippet - Loading Function P4:
    string type = tokens[0];
// END

    Explanation: This one is pretty simple, since every book is marked if it's `Literature` or `Magazine` we can easily check using the first token
    to see what type of book it is. ex: `Literature|The Great Gatsby|F. Scott Fitzgerald|180|0|Classic|English` is a Literature book

Code Snippet - Loading Function P5:
    if (type == "Literature" && tokens.size() == 7) {
        string title = tokens[1];
        string author = tokens[2];
        int pages = stoi(tokens[3]);
        bool borrowed = (tokens[4] == "1");
        string genre = tokens[5];
        string language = tokens[6];

        Books.push_back(new Literature(title, author, pages, borrowed, genre, language));
    }
    else if (type == "Magazine" && tokens.size() == 7) {
        string title = tokens[1];
        string author = tokens[2];
        int pages = stoi(tokens[3]);
        bool borrowed = (tokens[4] == "1");
        int issueNo = stoi(tokens[5]);
        string topic = tokens[6];

        Books.push_back(new Magazine(title, author, pages, borrowed, issueNo, topic));
    }
    else {
        cout << "Invalid line in save file: " << line << "\n";
    }
// END

    Explanation: This last part's pretty simple to be honest, I'm sure everyone can see that it's
    just reading the first token; token[0] and checking if it's Literature or Magazine.

    It also checks if it's the right size, just to make sure it doesn't input a record if it's missing a token.

    Then bingo-bango it takes all the tokens and creates it's respective object and inserts it into the books vector in the library.

| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |