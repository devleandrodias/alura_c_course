#define SIZE_SECRET_WORD 20

// Header files

void kick(int *estimate, char estimates[26]);
void showHeader();
void addNewWord();
void chooseWord();
void drawGallows();

int alreadyKicked(char letter);
int win();
int lost();
