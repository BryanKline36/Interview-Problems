#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int i;
    pair<string, int> testPair;
    map<string, int> testMapOne;
    map<string, int> testMapTwo;   
    multimap<string, int> testMultimap;    
    string names[10] = {"Jerome", "Bill Paxton", "Name", "Duke", "Larry", "CeleryMan", "Hot & Spicy", "Duke", "Hunter", "Duke"};
    multimap<string, int>:: iterator multimapIterator;

    for(i = 0; i < 10; i++)
    {
    	testMapOne[names[i]] = i + 10;

        testPair.first = names[i];
        testPair.second = i + 31;

        testMapTwo.insert(testPair);

        testPair.second = i + 52;

        testMultimap.insert(testPair);
    }

    cout << "Answer 1:" << endl;
    cout << testMapOne[names[1]] << endl;

    cout << "Answer 2:" << endl;
    cout << testMapOne["Name"] << endl;

    cout << "Answer 3:" << endl;
    cout << testMapTwo["Duke"] << endl;

    multimapIterator = testMultimap.find("Duke");

    cout << "Answer 4:" << endl;
    cout << multimapIterator->second << endl; 

    multimapIterator++;
    cout << "Answer 5:" << endl;
    cout << multimapIterator->second << endl; 

    multimapIterator++;
    cout << "Answer 6:" << endl;
    cout << multimapIterator->second << endl; 
    
    return 0;
}

/*
    Output:
    
    Answer 1:
	11
	Answer 2:
	12
	Answer 3:
	34
	Answer 4:
	55
	Answer 5:
	59
	Answer 6:
	61


*/
