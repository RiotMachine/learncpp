namespace Characters
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

int main()
{
    Characters::MonsterType monster{ Characters::troll };
    return 0;
}
