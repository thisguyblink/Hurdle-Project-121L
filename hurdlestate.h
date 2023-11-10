#pragma once

#include <map>
#include <string>
#include <vector>

#ifndef HURDLESTATE_H
#define HURDLESTATE_H

class HurdleState {
 public:
  HurdleState(const std::string& answer) 
            : secret_hurdle_(answer), current_word_(""), game_status_("active") {}
  std::string SecretHurdle() const;
  std::vector<std::string> GuessedWords() const;
  std::vector<std::string> WordColors();
  void SetHurdle(std::string hurdle);
  void LetterEntered(char let);
  void LetterDeleted(); 
  void WordSubmitted();
  void NewHurdle();
  std::string GameStatus();
  std::string ErrorMessage();
  std::string OneWordCol(const std::string& word);
  int Guesses();
  void SetError(std::string message);
  std::string CurrentWord();
  void ResetCurWord();
  //=================== YOUR CODE HERE ===================
  // TODO: Add the constructor(s), accessors, mutators,
  // and any other member function you may need here.
  //======================================================

 private:
  std::string secret_hurdle_{""};
  std::vector<std::string> guessed_words_;
  std::string current_word_;
  std::string game_status_;
  std::string error_;
  int guess_;
  //=================== YOUR CODE HERE ===================  
  // TODO: Add any member variables you need here to store
  // the state of the game. What information needs to be
  // stored to fully represent the game state at a single
  // point in time?
  //======================================================
};

#endif  // HURDLESTATE_H
