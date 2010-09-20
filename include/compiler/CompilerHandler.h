#include <iostream>
#include <map>
#include "Kernel.h"
#include "ObjectMgr.h"
#include "Player.h"
string Classes_String[] =
{
    "guerrier",
    "paladin",
    "chasseur",
    "voleur",
    "pretre",
    "chevalier de la mort",
    "chaman",
    "magicien",
    "demoniste",
    "",
    "druide"
};
string Races_String[] =
{
    "humain",
    "orc"
    "nain",
    "elfe de la nuit",
    "mort-vivant",
    "tauren",
    "gnome",
    "troll",
    "gobelin",
    "elfe de sang",
    "draenei",
    //RACE_FEL_ORC        = 12,
    //RACE_NAGA           = 13,
    //RACE_BROKEN         = 14,
    //RACE_SKELETON       = 15,
    //RACE_VRYKUL         = 16,
    //RACE_TUSKARR        = 17,
    //RACE_FOREST_TROLL   = 18,
    //RACE_TAUNKA         = 19,
    //RACE_NORTHREND_SKELETON = 20,
    //RACE_ICE_TROLL      = 21
};
using namespace std;
class AimlCompiler
{
    public:
        static string process(string func, map<string,string> args, Player *player)
        {
            cout << "Processing compiler code ..." << endl;
            string answer = "";
            if (func=="GetPlayer")
            {
                cout << "Processing GetPlayer ..." << endl;
                Player *p = sObjectMgr.GetPlayer(args["name"].c_str());
                string prop = args["property"];
                if (p)
                {
                    if (prop=="EXIST") return "true";
                    if (prop=="CLASS") return Classes_String[p->getClass()];
                    if (prop=="RACE") return Races_String[p->getRace()];
                }
                else if (prop=="EXIST") return "false";
            }
            return answer;
        }
    private:
};
