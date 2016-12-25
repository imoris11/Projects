/* Strings to try
program calculation1
begin
Alpha12 = 12.45 while ( I <= 10 ) begin
Alpha12 = Alpha12 + 2
I= I+3 end
Alpha12 = 14.56 + Beta end

//Example 2
program calculation2
begin
Alpha12 = 12.45 while ( I <= 10 ) begin
Alpha12 = Alpha12 + 2 * I
I= I+3
While ( Alpha12 + 1 > Beta + 12.45) begin
Beta = Beta + 1 end
C123 = C123 * I – Beta * 12.34 + 45.45 -1200 end
Alpha12 = 14.56 + Beta * 34 – 10 + 2.45676 * C123 end

 */
//Expression  Parser - Example 2 of Recursive Descent Parser
//Program -- By Prof. Barimani for Compiler Construction class - Fall 2016- Updated 11-12-2016
#include <iostream>
#include <fstream>
using namespace std;
//Parser Syntax Errors generated
#define InvalidFactor_ERR      "..Expect to see ID or Inumber\n****Rejected****\n";
#define EC_ERR              "..Saw unexpected Terminal\n****Rejected****\n";
#define LEX_ERR1			"..LEX ERROR:  invalid char ";
#define R_ERR               "..Syntax Error: Missing keyword 'program'\n";
#define ID_ERR              "..Syntax Error: Missing keyword 'ID'\n";
#define P_ERR1                 "..Syntax Error: Missing ')'\n";
#define P_ERR2                 "..Syntax Error: Missing '('\n";
#define B_ERR                 "..Syntax Error: Missing Comparison";
#define AEQ_ERR                 "..Syntax Error: Missing Char\n";
#define end_Error               "..Syntax Error: Expecting keyword 'begin' or 'end'\n";
//Grammar definition
#define root 			"<ProgBlock>	    ::= program ID   <Block>  \n";
#define BlockTree		 "<Block> 	    ::= begin <Sts>  end  \n";
#define STree_1		         "<Sts> 	    ::= ID   =   <Expression> <Sts>     \n";
#define STree_2		         "<Sts> 	    ::= while ( <booleanE> ) <Block> <Sts>  \n";
#define STree_3 		 "<Sts> 	    ::= empty\n";
#define BTree_1 		"< booleanE >       ::= < Expression >  == < Expression > \n";
#define BTree_2 		"< booleanE >       ::= < Expression >  <   < Expression > \n";
#define BTree_3 		"< booleanE >       ::= < Expression >  >   < Expression > \n";
#define BTree_4 		"< booleanE >       ::= < Expression >  <= < Expression > \n";
#define BTree_5 		"< booleanE >       ::= < Expression >  >= < Expression > \n";
#define ExpressionTree      "<Expression>   ::= <Term> <Epression_P>\n";
#define Expression_PTree1   "<Expression_P>  ::= +<Term> <Expression_P>\n";
#define Expression_PTree2 "<Expression_P> ::= -<Term> <Expression_P>\n";
#define Expression_PTree3   "<Expression_P>   ::= empty\n";
#define TermTree            "<Term>         ::= <Factor><Term_P>\n";
#define Term_PTree1         "<Term_P>       ::= *<Factor><Term_P>\n";
#define Term_PTree2         "<Term_P>       ::= empty\n";
#define FactorTree1         "<Factor>       ::= ID";
#define FactorTree2         "<Factor>       ::= INumber";
#define FactorTree3         	"<Factor>           ::= RNumber";
#define FactorTree4         	"<Factor>           ::=  (  <Expression>  ) \n";

//enum lexType { ID, INumber, lowOp, highOp, Eof }; <------Important changes to be used in your final project
enum lexType { INumber, RNumber, ID, ID_kwProgram, ID_kwBegin, ID_kwEnd, ID_kwWhile, lowOp, highOp, Eof, AEQ, EQ, LT, GT, LE, GE, LP, RP };

lexType tt;
int R=0;
bool show=false;
string code="MOV";
int state = 0;
char ch;
ifstream infile;
ofstream outFile;
char terminal[80];
int i;
bool done;
bool unget_failed=false;
bool flag=false;
bool booleans=false;
void Term();
void Expression();
void Expression_P();
void Factor();
void Term_P();
void Block();
void Sts();
void Booleans();
void PAUSE()
{
    cout << "Press any key to exit.."; cin.get(); exit(1);
}

//**************************** Lexical Anlyzer**************
int transfer(int tstate)
{
    infile.unget();
    switch (tstate)
    {
        case 0: return 3;
        case 3: return 5;
        case 5: return 8;
        case 9: return 12;
        default: return -1;
    }
}

void finalstate(int fstate)
{
    switch (fstate)
    {
        case 2:
            tt = INumber;
            infile.unget(); done = true; terminal[i] = '\0';
            break;
        case 4:
            tt = lowOp; terminal[i] = '\0'; done = true;
            break;
        case 7: 
            terminal[i] = '\0';
            if (strcmp(terminal, "program") == 0)
                tt = ID_kwProgram;
            else
                if (strcmp(terminal, "begin") == 0 )
                    tt = ID_kwBegin;
                else
                    if (strcmp(terminal, "end") == 0)
                        tt = ID_kwEnd;
                    else
                        if (strcmp(terminal, "while") == 0 )
                            tt = ID_kwWhile;
                        else
                            tt = ID;
            done = true;
            infile.unget();
            break;
        case 21:
            infile.unget(); state = 0;
            break;
        case 11:
            tt = highOp; terminal[i] = '\0'; done = true;
            break;
        case 14:
            booleans=true;
            tt=GE; terminal[i]='\0'; done=true;
            break;
        case 15:
            booleans=true;
            tt=GT; infile.unget();done=true; terminal[i]='\0';
            break;
        case 17:
            booleans=true;
            tt=LE; terminal[i]='\0'; done=true;
            break;
        case 18:
            tt=LT;booleans=true;
            infile.unget(); done=true; terminal[i]='\0';
            break;
        case 20:
            tt=EQ;booleans=true;
            terminal[i]='\0'; done=true;
            break;
        case 24:
            tt=RNumber;infile.unget(); terminal[i]='\0';done=true;
            break;
        case 25:
            tt=LP;done=true;
            break;
        case 26:
            tt=RP; done=true;
            break;
        case 27:
            tt=AEQ;done=true;infile.unget();terminal[i]='\0';
            break;
    }
    state=0;
}

void getTerminal()
{
    state = 0;
    terminal[0] = '\0';
    done = false;
    i = 0;
    //lex  driver
    while (!infile.eof() & !done)
    {
        switch (state)
        {
            case 0:
                ch = infile.get();
                if (isdigit(ch))
                {
                    terminal[i++] = ch; state = 1;
                }
                else //other
                {
                    state = transfer(0);
                }
                break;
            case 1:
                ch = infile.get();
                if (isdigit(ch))
                {
                    terminal[i++] = ch;
                    state = 1;
                }
                else if(ch=='.') //other
                {
                    terminal[i++]=ch;
                    state=22;
                }else{
                    finalstate(2);
                }
                break;
            case 3:
                ch = infile.get();
                if (ch == '+' || ch=='-')
                {
                    terminal[i++] = ch; finalstate(4);
                }
                else
                    if (ch == '*')
                    {
                        terminal[i++] = ch; finalstate(11);
                    }
                    else
                    {
                        state = transfer(3);
                    }
                break;
            case 5:
                ch = infile.get();
                if (isalpha(ch))
                {
                    terminal[i++] = ch; state = 6;
                }
                else
                {
                    state = transfer(5);
                }
                break;
            case 6:
                ch = infile.get();
                if (isdigit(ch) || isalpha(ch))
                {
                    terminal[i++] = ch; state = 6;
                }
                else
                {
                    finalstate(7);
                }
                break;
            case 8:
                ch = infile.get();
                if (ch == ' ')
                {
                    state = 9;
                }
                else
                {
                    if(ch=='('){
                        state=0;
                        finalstate(25);
                    }else
                        if(ch==')'){
                            state=0;
                            finalstate(26);
                        }else{
                            if(ch==EOF){
                                tt=Eof;
                                done=true;
                            }
                        }
                }
                break;

            case 9:
                ch = infile.get();
                if (ch == ' ')
                {
                    state = 9;
                }
                else
                {
                   state=transfer(9);
                }
                break;
            case 12:
                ch=infile.get();
                if(ch=='>'){
                    terminal[i++] = ch;
                    state=13;
                }else if (ch=='<'){
                    terminal[i++] = ch;
                    state=16;
                }else if(ch=='='){
                    terminal[i++] = ch;
                    state=19;
                }else{
                    finalstate(21);
                }
                break;
            case 13:
                ch=infile.get();
                if(ch=='=')
                {
                    terminal[i++] = ch;
                    finalstate(14);
                }
                else
                    finalstate(15);
                break;
            case 16:
                ch=infile.get();
                if(ch=='=')
                {
                    terminal[i++] = ch;
                    finalstate(17);
                }
                else
                    finalstate(18);
                break;
            case 19:
                ch=infile.get();
                if(ch=='='){
                    terminal[i++]=ch;
                    finalstate(20);
                }else{
                    finalstate(27);
                }
                
                break;
            case 22:
                ch=infile.get();
                if(isdigit(ch))
                {
                    state=23;
                    terminal[i++]=ch;
                }else{
                    cout<<LEX_ERR1;
                    cout<<"[ "<<ch<<" ] \n";
                    PAUSE();
                }
                break;
            case 23:
                ch=infile.get();
                if(isdigit(ch)){
                    state=23;
                    terminal[i++]=ch;
                }else{
                    finalstate(24);
                }
                break;
        }
    }//end of while
    
}
///////*************************  Parser (Syntax Analyzer) ******************
void Root(){
    //#define root 			"<ProgBlock>	    ::= program ID   <Block>  \n";
    cout<<root;
    getTerminal();
    if (tt == ID_kwProgram)
    {
    cout << "" << terminal << "";
    getTerminal();
    if (tt == ID){
        cout << " " << terminal << "\n";
        Block();
    }else{
        cout<<ID_ERR;
        PAUSE();
    }
    }else{
        cout<<R_ERR;
        PAUSE();
    }
}
void Block(){
    //#define BlockTree		 "<Block> 	    ::= begin <Sts>  end  \n";
    cout<<BlockTree;
    getTerminal();
    if(tt==RP){
        getTerminal();
    }
    if (tt == ID_kwBegin)
    {
        cout << "(" << terminal << ")\n";
        Sts();
    }
    if (tt == ID_kwEnd)
    {
        cout << "(" << terminal << ")\n";
    }else{
        
        cout<<end_Error;
        PAUSE();
    }
}
void Sts(){
//#define STree_1		         "<Sts> 	    ::= ID   =   <Expression> <Sts>     \n";
//#define STree_2		         "<Sts> 	    ::= while ( <booleanE> ) <Block> <Sts>  \n";
//#define STree_3 		 "<Sts> 	    ::= empty\n";
    
    getTerminal();
    if (tt == ID)
    {
        R++;
        string id=terminal;
        cout << STree_1;
        getTerminal();
        if(tt==AEQ){
            cout<<FactorTree1;
            cout<<""<<terminal<<"";
        }else{
            cout<<AEQ_ERR;
            PAUSE();
        }
        cout << "( " << id << " )\n";
        show=true;
        Expression();
        outFile<<code<<" "<<id<<", "<<"R"<<R<<" "<<endl;
        R--;
        show=false;
        Sts();
    }else if(tt==ID_kwWhile) {
        cout<<STree_2;
        Booleans();
        Block();
        Sts();
    }
        else{
            cout<<STree_3;
            if(unget_failed){
                cout<<"(end)"<<endl;
            }
            if(tt==Eof){
                PAUSE();
            }
        }
}
void Booleans(){
//#define BTree_1 		"< booleanE >       ::= < Expression >  == < Expression > \n";
//#define BTree_2 		"< booleanE >       ::= < Expression >  <   < Expression > \n";
//#define BTree_3 		"< booleanE >       ::= < Expression >  >   < Expression > \n";
//#define BTree_4 		"< booleanE >       ::= < Expression >  <= < Expression > \n";
//#define BTree_5 		"< booleanE >       ::= < Expression >  >= < Expression > \n";
    getTerminal();
    if(tt==LP){
        Expression();
    }else{
        cout<<P_ERR1;
        PAUSE();
    }
    if(flag){
        if (tt == EQ)
        {
            cout << BTree_1;
        }
        else
            if (tt == LT)
            {
                cout << BTree_2;
            }
            else
                if (tt == GT)
                {
                    cout << BTree_3;
                }
                else
                    if (tt == LE)
                    {
                        cout << BTree_4;
                    }
                    else
                        if (tt == GE)
                        {
                            cout << BTree_5;
                        }else{
                            cout<<B_ERR;
                            PAUSE();
                        }flag=false;
    }else{
        getTerminal();
        if (tt == EQ)
        {
            cout << BTree_1;
        }
        else
            if (tt == LT)
            {
                cout << BTree_2;
            }
            else
                if (tt == GT)
                {
                    cout << BTree_3;
                }
                else
                    if (tt == LE)
                    {
                        cout << BTree_4;
                    }
                    else
                        if (tt == GE)
                        {
                            cout << BTree_5;
                        }else{
                             cout<<B_ERR;
                            cout<<endl;
                            PAUSE();
                        }

    }

    Expression();
    getTerminal();
    if(tt !=RP){
        cout<<P_ERR2;
        PAUSE();
    }
}
void ungetChar(int size){
    for(int i=0; i<size; i++){
        infile.unget();
    }
}
void Expression()
{
    //	#define ExpressionTree      "<Expression>   ::= <Term> <Epression_P>\n";
    cout << ExpressionTree;
    Term();
    Expression_P();
}

void Expression_P()
{   //#define Expression_PTree1   "<Epression_P>  ::= + <Term> <Expression_P>\n";
    //#define Expression_PTree2 "<Expression_P> ::= -<Term> <Expression_P>\n";
    //#define Expression_PTree2   "<Expression>   ::= empty\n";
    if(flag)
        return;
    getTerminal();
    if (tt == lowOp)
    {
        if(strcmp(terminal, "+")==0){
         cout << Expression_PTree1;
            if(show)
                code="ADD";
        }else{
            cout<<Expression_PTree2
            code="SUB";
        }
        
        Term();
        Expression_P();
    }else
       {
        cout << Expression_PTree3;
           if(tt==ID_kwEnd){
               infile.unget();infile.unget();infile.unget();
           }else
               if(tt==ID_kwBegin){
                   infile.unget();infile.unget();infile.unget();infile.unget();infile.unget();
               }else if(tt==ID_kwWhile){
                   infile.unget();infile.unget();infile.unget();infile.unget();infile.unget();
               }
         else {
            infile.unget();
        }
    }
}

void Term()
{
    //#define TermTree          "<Term>         ::= <Factor><Term_P>\n";
    cout << TermTree;
    Factor();
    Term_P();
}

void Factor()
{
    //#define FactorTree1       "<Factor>       ::= ID";
    //#define FactorTree2       "<Factor>       ::= INumber";
    //#define FactorTree3         	"<Factor>           ::= RNumber";
    //#define FactorTree4         	"<Factor>           ::=  (  <Expression>  ) \n";
    getTerminal();
    if(tt==INumber){
        cout<<FactorTree2;
        cout<<"( "<<terminal<<" )\n";
        if(show)
        outFile<<code<<" R"<<R<<", "<<terminal<<endl;
        
    }else
        if(tt==RNumber){
            cout<<FactorTree3;
            cout<<"( "<<terminal<<")\n";
            if(show)
            outFile<<code<<" R"<<R<<", "<<terminal<<endl;
        }
        else
        if(tt==ID){
            cout<<FactorTree1;
            cout<<"( "<<terminal<<")\n";
            if(show)
            outFile<<code<<" R"<<R<<", "<<terminal<<endl;
        }else
        if(tt==LP){
            Expression();
            getTerminal();
            if(tt != RP){
                PAUSE();
            }
        }else{
            return;
        }
    code="MOV";
    
}

void Term_P()
{
    //#define Term_PTree1        "<Term_P>       ::= highOp(*) <Factor><Term_P>";
    //#define Term_PTree2        "<Term_P>       ::= empty\n";
    getTerminal();
    if(booleans){
        flag=true;
        booleans=false;
        return;
    }
    if (tt == highOp)
    {
        cout << Term_PTree1;
        if(show)
            code="MUL";
        Factor();
        Term_P();
    }else if(tt==ID_kwWhile){
        cout << Term_PTree2;
        ungetChar(5);
    }else
        if(tt==ID_kwEnd){
            cout << Term_PTree2;
            if(infile.unget()){
                ungetChar(2);
            }else{
                unget_failed=true;
            }
        }else
        if(tt==ID_kwBegin){
            cout << Term_PTree2;
            ungetChar(5);
        }
    else
    {
        cout << Term_PTree2;
        if(lowOp)
        {
            infile.unget();
        }
    }
}
int main()
{
    
    infile.open("/Users/richardigbiriki/Downloads/Compiler/TestString.txt", ios::in);
    if (infile.fail())
    {
        cout << "cannot open file!!\n";
        system("PAUSE");
        exit(1);
    }
    outFile.open("/Users/richardigbiriki/Downloads/Compiler/assembly.txt");
    Root();
    if (!infile.eof())
    {
        cout << EC_ERR;
    }
    outFile.close();
    PAUSE();
    infile.close();
    return 0;
}
