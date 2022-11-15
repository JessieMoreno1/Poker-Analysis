cmake_minimum_required(VERSION 3.23)
project(DeckofCards)

set(CMAKE_CXX_STANDARD 14)

add_executable(DeckofCards main.cpp Deck.cpp Deck.h RankEnum.h SuitEnum.h Card.cpp Card.h CardHand.cpp CardHand.h CardHandScorer.cpp CardHandScorer.h PokerScore.cpp PokerScore.h)
