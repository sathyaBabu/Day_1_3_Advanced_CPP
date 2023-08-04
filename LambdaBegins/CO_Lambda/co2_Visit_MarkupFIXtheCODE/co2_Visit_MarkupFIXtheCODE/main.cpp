//
//  main.cpp
//  co2_Visit_MarkupFIXtheCODE
//
//  Created by Sathya Babu on 30/11/21.


//****************** FIX the code ************************
// Check if the design is correct
// Put your right thoughts and re impliment the code

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <variant>

#include <list>
using namespace std;

struct Document {
    virtual void add_to_list(const string &line) = 0;
};
//**** What if if I have to bring in xml ppt and so on..
struct Markdown : public Document {
    void add_to_list(const string &line) { m_content.push_back(line); }

    string          m_start = "* ";
    list<string>    m_content;
};

struct HTML : public Document {
    void add_to_list(const string &line) { m_content.push_back(line); }

    string          m_start = "<li>";
    string          m_end = "</li>";
    list<string>    m_content;
};

/* ------------------------------------ Visitor ------------------------------------- */
//*******  FIX THIS PART to Overide - Lambda
// This is not folllowing SOLID Open close principle
struct DocumentPrinter {
    void operator()(Markdown &md) {
        for (auto &&item : md.m_content)
            cout << md.m_start << item << endl;
    }
    void operator()(HTML &hd){
        cout << "<ul>" << endl;
        for (auto &&item : hd.m_content)
            cout << "\t" << hd.m_start << item << hd.m_end << endl;
        cout << "</ul>" << endl;
    }
};

// 
/* ---------------------------------------------------------------------------------- */
using document = std::variant<Markdown, HTML>;

int main() {

    HTML hd;
    Document   doc = &hd;
    doc.add_to_list("HTML header... <H> .... </H>!");
    DocumentPrinter dp;
    std::visit(dp, doc);
    return EXIT_SUCCESS;
}
