struct card{
  char suit;
  int rank;
  card(){
  }
  bool operator <(card C){
    return rank < C.rank || rank == C.rank && suit < C.suit;
  }
};
istream& operator >>(istream& is, card& C){
  string S;
  is >> S;
  C.suit = S[0];
  if (S[1] == 'A'){
    C.rank = 14;
  } else if (S[1] == 'K'){
    C.rank = 13;
  } else if (S[1] == 'Q'){
    C.rank = 12;
  } else if (S[1] == 'J'){
    C.rank = 11;
  } else if (S[1] == 'T'){
    C.rank = 10;
  } else {
    C.rank = S[1] - '0';
  }
  return is;
}
enum poker_hand{HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH, ROYAL_STRAIGHT_FLUSH};
vector<int> hand(array<card, 5> C){
  sort(C.begin(), C.end());
  bool is_flush = true;
  for (int i = 1; i < 5; i++){
    if (C[i].suit != C[0].suit){
      is_flush = false;
    }
  }
  if (is_flush && C[4].rank == 14 && C[0].rank == 10){
    return {ROYAL_STRAIGHT_FLUSH};
  } else if (is_flush && C[4].rank - C[0].rank == 4){
    return {STRAIGHT_FLUSH, C[4].rank};
  } else if (is_flush && C[3].rank == 5 && C[4].rank == 14){
    return {STRAIGHT_FLUSH, 5};
  } else if (C[0].rank == C[3].rank){
    return {FOUR_OF_A_KIND, C[0].rank, C[4].rank};
  } else if (C[1].rank == C[4].rank){
    return {FOUR_OF_A_KIND, C[1].rank, C[0].rank};
  } else if (C[0].rank == C[2].rank && C[3].rank == C[4].rank){
    return {FULL_HOUSE, C[0].rank, C[3].rank};
  } else if (C[2].rank == C[4].rank && C[0].rank == C[1].rank){
    return {FULL_HOUSE, C[2].rank, C[0].rank};
  } else if (is_flush){
    return {FLUSH, C[4].rank, C[3].rank, C[2].rank, C[1].rank, C[0].rank};
  } else if (C[1].rank - C[0].rank == 1 && C[2].rank - C[1].rank == 1 && C[3].rank - C[2].rank == 1 && C[4].rank - C[3].rank == 1){
    return {STRAIGHT, C[4].rank};
  } else if (C[0].rank == 2 && C[1].rank == 3 && C[2].rank == 4 && C[3].rank == 5 && C[4].rank == 14){
    return {STRAIGHT, 5};
  } else if (C[0].rank == C[2].rank){
    return {THREE_OF_A_KIND, C[0].rank, C[4].rank, C[3].rank};
  } else if (C[1].rank == C[3].rank){
    return {THREE_OF_A_KIND, C[1].rank, C[4].rank, C[0].rank};
  } else if (C[2].rank == C[4].rank){
    return {THREE_OF_A_KIND, C[2].rank, C[1].rank, C[0].rank};
  } else if (C[0].rank == C[1].rank && C[2].rank == C[3].rank){
    return {TWO_PAIR, C[2].rank, C[0].rank, C[4].rank};
  } else if (C[0].rank == C[1].rank && C[3].rank == C[4].rank){
    return {TWO_PAIR, C[3].rank, C[0].rank, C[2].rank};
  } else if (C[1].rank == C[2].rank && C[3].rank == C[4].rank){
    return {TWO_PAIR, C[3].rank, C[1].rank, C[0].rank};
  } else if (C[0].rank == C[1].rank){
    return {ONE_PAIR, C[0].rank, C[4].rank, C[3].rank, C[2].rank};
  } else if (C[1].rank == C[2].rank){
    return {ONE_PAIR, C[1].rank, C[4].rank, C[3].rank, C[0].rank};
  } else if (C[2].rank == C[3].rank){
    return {ONE_PAIR, C[2].rank, C[4].rank, C[1].rank, C[0].rank};
  } else if (C[3].rank == C[4].rank){
    return {ONE_PAIR, C[3].rank, C[2].rank, C[1].rank, C[0].rank};
  } else {
    return {HIGH_CARD, C[4].rank, C[3].rank, C[2].rank, C[1].rank, C[0].rank};
  }
}