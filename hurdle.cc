#include "hurdle.h"

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement the member
// functions declared in the header, only if you didn't implement
// them inline in the header.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the HurdleGame class.
// ===================================================================
void HurdleGame::NewHurdle() {
  hurdle_state_.HurdleState::NewHurdle();
}
void HurdleGame::LetterEntered(char key) {
  hurdle_state_.HurdleState::LetterEntered(key);
}
void HurdleGame::WordSubmitted() {
  hurdle_state_.SetError("");
  if (!(hurdlewords_.HurdleWords::IsGuessValid(hurdle_state_.HurdleState::CurrentWord()))) {
    hurdle_state_.HurdleState::SetError("Guess is invalid!");
  } 
  hurdle_state_.HurdleState::WordSubmitted();
}
void HurdleGame::LetterDeleted() {
  hurdle_state_.HurdleState::LetterDeleted();
}

crow::json::wvalue HurdleGame::JsonFromHurdleState() {
  // The JSON object to return to the Hurdle Frontend.
  crow::json::wvalue hurdle_state_json({});
  
  // ===================== YOUR CODE HERE =====================
  // Fill the hurdle_state_json with the data expected by the
  // Hurdle frontend. The frontend expects the following keys:
  //   1. "answer"
  //   2. "boardColors"
  //   3. "guessedWords"
  //   4. "gameStatus"
  //   5. "errorMessage"
  //   6. [OPTIONAL] "letterColors"
  // See the "JSON Response" section of tinyurl.com/cpsc121-s23-hurdle
  //
  hurdle_state_json["answer"] = hurdle_state_.SecretHurdle();
  hurdle_state_json["boardColors"] = hurdle_state_.WordColors();
  hurdle_state_json["guessedWords"] = hurdle_state_.GuessedWords();
  hurdle_state_json["gameStatus"] = hurdle_state_.GameStatus();
  if ((hurdle_state_.ErrorMessage().length() != 0)) {
    hurdle_state_json["errorMessage"] = hurdle_state_.ErrorMessage();
  }
  
  
  // You can set the key in the JSON to a value like so:
  //             hurdle_state_json[<key>] = <value>
  //
  // See below for an example to set the "answer" key:
  // Replace this!
  // ==========================================================
  return hurdle_state_json;
}
