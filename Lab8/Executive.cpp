/**
*	@file Executive.cpp
*	@author Zachary Bruennig 
*	@date 11/12/16
*	@brief Handles all the i/o for this program. Stores no real data, except the BSTs which holds everything
*/

#include "Executive.h"

std::ofstream outFile; //this is REALLY bad practice, 
//but it's the only way I could get writeOutput to be static and maintain it's function

Executive::Executive(std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName);
    if(!inFile.is_open())
        m_fileExists = false;
    else
    {
        m_fileExists = true;
        m_pokedex = new BinarySearchTree<Pokemon, std::string>;
        
        std::string line;
        while(std::getline(inFile, line))
        {
            std::string american, japanese;
            int number;
            
            american = line.substr(0, line.find(","));
            line = line.substr(line.find(",")+1, line.length());
            
            std::string temp = line.substr(0, line.find(","));
            number = std::stoi(temp);
            
            japanese = line.substr(line.find(",")+1, line.length()-1); 
            // -1 gets rid of the \n character at the end
            
            american = standardize(american);
            japanese = standardize(japanese);
            
            Pokemon curr(american, japanese, number);
            m_pokedex->add(curr);
        }
    }
}

Executive::~Executive()
{
    if(m_fileExists)
        delete m_pokedex;
    if(m_isCopyInitialized)
        delete m_copy;
}

void Executive::save(std::string fileName, bool copy, int traversal)
{
            outFile.open(fileName);
            
            //traverse
            if(!copy)
            {
                if(traversal==1)
                    m_pokedex->inorderTraverse(writeOutput);
                if(traversal==2)
                    m_pokedex->preorderTraverse(writeOutput);
                if(traversal==3)
                    m_pokedex->postorderTraverse(writeOutput);
            }
            else
            {
                if(traversal==1)
                    m_copy->inorderTraverse(writeOutput);
                if(traversal==2)
                    m_copy->preorderTraverse(writeOutput);
                if(traversal==3)
                    m_copy->postorderTraverse(writeOutput);
            }
            outFile.close();
}

void Executive::writeOutput(Pokemon& curr) //make sure m_outFile is open at this point
{
    outFile << curr.toString();
    outFile << "\n";
}

void Executive::printTree(Pokemon& curr)
{
    std::cout << curr.toString() << '\n';
}

void Executive::testAdds(BinarySearchTree<Pokemon, std::string> bst) //NOTE: Passed by value!!!
{
    std::string american, japanese;
    int number;
                
    std::cout << "Input new Pokemon's american name: ";
    std::cin.ignore(1, '\n');
    std::getline(std::cin, american); //CHANGE
    std::cout << "Input new Pokemon's japanese name: ";
    std::getline(std::cin, japanese); //CHANGE
    std::cout << "Input new Pokemon's number: ";
    std::cin >> number;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cin >> number;
    }
    
    Pokemon curr(american, japanese, number); //the \n is for file formatting later
    bst.add(curr);
    
    american = standardize(american);
    japanese = standardize(japanese);
    
    bst.inorderTraverse(printTree);
}

void Executive::testRemoves(BinarySearchTree<Pokemon, std::string> bst) //NOTE: Passed by value!!!
{
    std::string nameToRemove;
    std::cout << "Input Pokemon to remove: ";
    std::cin.ignore(1, '\n');
    std::getline(std::cin, nameToRemove); //CHANGE
    
    nameToRemove = standardize(nameToRemove);
    
    bool success = bst.remove(nameToRemove);
    if(success==false)
        std::cout << "Couldn't remove Pokemon from the Pokedex\n";
    
    bst.inorderTraverse(printTree);
}

void Executive::testWriteToFile(BinarySearchTree<Pokemon, std::string> bst) //NOTE: Passed by value!!!
{
    std::string fileName;
    std::cout << "Input file name: ";
    std::cin >> fileName;
    
    outFile.open(fileName);
    bst.inorderTraverse(writeOutput);
    outFile.close();
}

std::string Executive::standardize(std::string input)
{
    for(unsigned int i=0; i<input.length(); i++)
    {
        if(i==0 || input[i-1]==' ')
            input[i]=toupper(input[i]);
        else
            input[i]=tolower(input[i]);
    }
    return input;
}

void Executive::run()
{
    if(!m_fileExists)
        std::cout << "Error: File could not be read.\n";
    while(m_fileExists)
    {
        char option = ' ';
        std::cout << "\nMake a choice:\n";
        std::cout << "1) Search the tree using the Pokemon's american name\n";
        std::cout << "2) Copy and create an editable Pokedex\n";
        std::cout << "3) Add to copy\n";
        std::cout << "4) Remove from copy\n"; //should have called 2 before trying 3 or 4
        std::cout << "5) Save to a file\n";
        std::cout << "6) Test\n";
        std::cout << "7) Quit\n";
    
        while(option!='1' && option!='2' && option!='3' && option!='4' && option!='5' && option!='6'
            && option!='7') {std::cin >> option;}
            
        if(option=='1')
        {
            std::string name;
            std::cout << "Input Pokemon's american name: ";
            std::cin.ignore(1, '\n');
            std::getline(std::cin, name); //CHANGE
            
            name = standardize(name);
            
            if(m_pokedex->contains(name))
            {
                Pokemon match = m_pokedex->getEntry(name);
                std::cout << match.toString() << '\n';
            }
            else
            {
                std::cout << "No Pokemon found!\n";
            }
        }
        else if(option=='2')
        {
            m_copy = new BinarySearchTree<Pokemon, std::string>;
            m_copy->copy(m_pokedex);
            m_isCopyInitialized = true;
        }
        else if(option=='3')
        {
            if(!m_isCopyInitialized)
                std::cout << "Error: Copy not created!\n";
            else
            {
                std::string american, japanese;
                int number;
                
                std::cout << "Input new Pokemon's american name: ";
                std::cin >> american; //CHANGE
                std::cout << "Input new Pokemon's japanese name: ";
                std::cin >> japanese; //CHANGE
                std::cout << "Input new Pokemon's number: ";
                std::cin >> number;
                while(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> number;
                }
                
                american = standardize(american);
                japanese = standardize(japanese);
                               
                Pokemon curr(american, japanese, number); //the \n is for file formatting later
                m_copy->add(curr);
            }
        }
        else if(option=='4')
        {
            if(!m_isCopyInitialized)
                std::cout << "Error: Copy not created!\n";
            else
            {
                std::string nameToRemove;
                std::cout << "Input Pokemon to remove: ";
                std::cin.ignore(1, '\n');
                std::getline(std::cin, nameToRemove); //CHANGE
                
                nameToRemove = standardize(nameToRemove);
                
                bool success = m_copy->remove(nameToRemove);
                if(success==false)
                    std::cout << "Couldn't remove Pokemon from the Pokedex\n";
            }
            
        }
        else if(option=='5')
        {
            std::string fileName;
            int traversal;
            bool copy=false;
            
            std::cout << "Input traversal method (1=inorder, 2=preorder, 3=postorder): ";
            std::cin >> traversal;
            while(std::cin.fail() && traversal!=1 && traversal!=2 && traversal!=3)
            { //guarantees valid input
                std::cin.clear();
                std::cin.ignore();
                std::cin >> traversal;
            }
            
            if(m_isCopyInitialized)
            {
                std::cout << "Save original or copy? (0=original, 1=copy): ";
                std::cin >> copy;
                while(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> copy;
                }
            }
            
            std::cout << "Input file name: ";
            std::cin >> fileName;
            
            save(fileName,copy,traversal);
            
        }
        else if(option=='6')
        {
            int choice;
            std::cout << "Which test do you want to run? (1=Add, 2=Remove, 3=Write to File): ";
            std::cin >> choice;
            while(std::cin.fail() && choice!=1 && choice!=2 && choice!=3)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cin >> choice;
            }
            BinarySearchTree<Pokemon, std::string>* temp = new BinarySearchTree<Pokemon, std::string>;
            temp->copy(m_pokedex);
            
            if(choice==1)
                testAdds(*temp);
            if(choice==2)
                testRemoves(*temp);
            if(choice==3)
                testWriteToFile(*temp);
            
            //delete temp; //Including this tries to delete something that's already been deleted, but
            //removing it causes a memory leak... (╯°□°）╯︵ ┻━┻
            //every time this else if block is run we lose 16 bytes... oh well.
        }
        else //will only happen if option == '7'
        {
            break;
        }
    }
}
