#include "hurdlestate.h"

std::string HurdleState::SecretHurdle() const {
    return secret_hurdle_;
  }
std::vector<std::string> HurdleState::GuessedWords() const {
    std::vector<std::string> words;
    for (std::string word : guessed_words_) {
      words.push_back(word);
    }
    return words;
  }
// std::string HurdleState::OneWordCol(const std::string& word) {
//   std::string char_col;
//   for (std::size_t i = 0; i < word.length() && i < secret_hurdle_.length(); i++) {
//     if (secret_hurdle_.substr(i, 1) == word.substr(i, 1)) {
//       char_col += "G";
//     } else if (word.find(secret_hurdle_.substr(i, 1)) != std::string::npos) {
//       char_col += "Y";
//     } else {
//       char_col += "B";
//     }
//   }
//   return char_col;
// }

// std::string HurdleState::OneWordCol(const std::string& word) {
//   std::string char_col{""};
//   std::map<std::string, int> let_col;
//   for (int i = 0; i < word.length() && i < secret_hurdle_.length(); i++) {
//     if (secret_hurdle_.substr(i, 1) == word.substr(i, 1)) {
//         char_col += "G";
//         if (let_col.count(word.substr(i,1)) == 0) {
//         let_col.insert(std::pair<std::string,int>(word.substr(i, 1), 1));
//         } 
//         if (let_col.count(word.substr(i,1)) == 1) {
//         let_col.at(word.substr(i, 1)) += 1;
//         }
//         }
//         if (let_col.count(word.substr(i,1)) == 0) {
//         let_col.insert(std::pair<std::string,int>(word.substr(i, 1), 0));
//         }     
//     else {
//       char_col += "B";
//     }
//   }
//   for (int i = 0; i < word.length() && i < secret_hurdle_.length(); i++) {
//     for (int t = 0; t < word.length(); t++) {
//         if (secret_hurdle_.substr(t, 1) == word.substr(i, 1)) {
//           for (int l = 0; l < word.length(); l++) {
//             if (secret_hurdle_.substr(l,1) == word.substr(i,1)) {
//               if (let_col.count(word.substr(i, 1)) == 1) {
//               let_col.at(word.substr(i, 1)) -= 1;
//                if (let_col.at(word.substr(i,1)) <= 1) {
//                  char_col.replace(i,1, "Y");
//                }
//               }
//               //char_col.replace(i,1, "Y");
//             }
//           }
//         }
//     }
//   }
//   return char_col;
// }
std::string HurdleState::OneWordCol(const std::string& word) {
  std::string char_col;
  std::map<char, int> col_map;

  for (int t = 0; t < word.length() && t < secret_hurdle_.length(); t++) {
    if (col_map.count(secret_hurdle_.at(t)) == 0) {
      col_map.insert(std::pair<char, int>(secret_hurdle_.at(t), 1));
    } else {
      col_map.at(secret_hurdle_.at(t)) += 1;
    }
  }

  for (int i = 0; i < word.length() && i < secret_hurdle_.length(); i++) {
    if (secret_hurdle_.at(i) == word.at(i)) {
      char_col += 'G';
      col_map.at(secret_hurdle_.at(i)) -= 1;
    } else {
      char_col += 'B';
    }
    }
  for (int t = 0; t < word.length() && t < secret_hurdle_.length(); t++) {
    for (int l = 0; l < word.length() && l < secret_hurdle_.length(); l++) {
    if (col_map.count(word.at(t)) == 1 && col_map.at(word.at(t)) > 0) {
      if (word.at(t) == secret_hurdle_.at(l) && char_col.at(t) != 'G') {
      char_col.replace(t, 1, "Y");
      col_map.at(word.at(t)) -= 1;
      }
    }
    }
  }
  return char_col;
}

// std::string HurdleState::OneWordCol(const std::string& word) {
//   std::string char_col;
//   std::map<char, int> col_map;
//   for (int t = 0; t < word.length() && t < secret_hurdle_.length(); t++) {
//     if (col_map.count(secret_hurdle_.at(t)) == 0) {
//     col_map.insert(std::pair<char, int>(secret_hurdle_.at(t), 1));
//     }
//     else {
//       col_map.at(secret_hurdle_.at(t)) += 1;
//     }
//   }
//   for (int i = 0; i < word.length() && i < secret_hurdle_.length(); i++) {
//     if (secret_hurdle_.at(i) == word.at(i)) {
//       char_col += 'G';
//       col_map.at(secret_hurdle_.at(i)) -= 1;
//     }
//     else {
//       char_col += 'B';
//     }
//     if (col_map.count(word.at(i)) == 1 ) {
//       if (col_map.count(word.at(i)) == 1 && col_map.at(word.at(i)) > 0){
//         for (int l = 0; l < word.length(); l++) {
//           if (word.at(i) == secret_hurdle_.at(l)) {
//           char_col.replace(i, 1, "Y");
//           }
//         col_map.at(word.at(i)) -= 1;
//         }
//       }
//     }
//   }
//   return char_col;
// }

// std::string HurdleState::OneWordCol(const std::string& word) {
//   std::string char_col{""};
//   for (int i = 0; i < word.length() && i < secret_hurdle_.length(); i++) {
//     bool found = false;
//     while (!found) {
//     if (secret_hurdle_.substr(i, 1) == word.substr(i, 1)) {
//         char_col += "G";
//         found = true;
//         break;
//     }
//     for (int t = 0; t < word.length() && !found; t++) {
//         if (secret_hurdle_.substr(t, 1) == word.substr(i, 1)) {
//           char_col += "Y";
//           found = true;
//           break;
//         }
//     }
//     if (!found) {
//       char_col += "B";
//       found = true;
//       break;
//     }
//     }
//   }
//   return char_col;
// }


std::vector<std::string> HurdleState::WordColors() {
  std::vector<std::string> all_colors;
  for (auto word : guessed_words_) {
    all_colors.push_back(OneWordCol(word));
  }
  return all_colors;
}
void HurdleState::SetHurdle(std::string hurdle) {
  secret_hurdle_ = hurdle;
}
void HurdleState::LetterEntered(char let) {
  if ((guessed_words_.size() != 0)  &&  (current_word_.length() != 0)) {
  guessed_words_.pop_back();
  }
  if (current_word_.length() < 5) {
  current_word_ += let;
  }
  guessed_words_.push_back(current_word_);
  error_ = "";
}
void HurdleState::LetterDeleted() {
  if (guessed_words_.size() != 0) {
    guessed_words_.pop_back();
  }
  if (current_word_.length() > 0) {
    current_word_.resize(current_word_.length() - 1);
  }
}
void HurdleState::WordSubmitted() {
  if (current_word_.length() < 5) {
    error_ = "Guess is too short!";
  } 
  if (current_word_.length() == 5) {
  if ((guessed_words_.size() < 6) && (current_word_ == secret_hurdle_)) {
    game_status_ = "win";
  } else if ((guessed_words_.size() == 6) && (current_word_ != secret_hurdle_)) {
    game_status_ = "lose";
  }
  guessed_words_.push_back(current_word_);
  guessed_words_.pop_back();
  current_word_.clear();
  if (guessed_words_.size() == 6 && game_status_ != "win") {
    game_status_ = "lose";
  }
  }
}
void HurdleState::NewHurdle() {
  current_word_ = "";
  game_status_ = "active";
  guessed_words_.clear();
  error_ = "";
}
std::string HurdleState::GameStatus() {
  return game_status_;
}
std::string HurdleState::ErrorMessage() {
  return error_;
}

void HurdleState::SetError(std::string message) {
  error_ = message;
}
std::string HurdleState::CurrentWord() {
  return current_word_;
}
void HurdleState::ResetCurWord() {
  current_word_ = "";
}
