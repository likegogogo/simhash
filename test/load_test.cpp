#include <iostream>
#include <ctime>
#include <fstream>
#include "../src/Simhasher.hpp"

using namespace Simhash;

void simhash(size_t times = 400)
{
    Simhasher simhasher("../dict/jieba.dict.utf8", "../dict/hmm_model.utf8", "../dict/idf.utf8", "../dict/stop_words.utf8");
    assert(simhasher);
    uint64_t value;
    string doc;
    
    ifstream ifs("../test/testdata/news_content.2");
    assert(ifs);
    doc << ifs;
    long beginTime = clock();
    for(size_t i = 0; i < times; i ++)
    {
        printf("process [%3.0lf %%]\r", 100.0*(i+1)/times);
        fflush(stdout);
        simhasher.make(doc, 5, value);
    }
    long endTime = clock();
    printf("\nextract: [%.3lf seconds]time consumed.\n", double(endTime - beginTime)/CLOCKS_PER_SEC);
}

int main(int argc, char ** argv)
{
    simhash();
    return EXIT_SUCCESS;
}
