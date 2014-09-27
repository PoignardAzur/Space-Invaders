


#ifndef HEADER_SPACE_STATS
#define HEADER_SPACE_STATS




struct SpaceStats
{
    bool continuePlaying;
    bool gameOverMode;
    int score;

    SpaceStats(bool nContinue = true, bool gameOver = false, int nScore = 0) : continuePlaying(nContinue), gameOverMode(gameOver), score(nScore)
    {}
};




#endif
