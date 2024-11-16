// tEM make a kool UPDAtE!

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>


// why did u lookin in ma code? btw tEM! iz VERYY!! happy cuz u r VERYY!! interested in tEMs! code

#define MAX_LINE_LENGTH 256
#define DICT_SIZE 114

typedef struct {
    char word[DICT_SIZE];
    char translation[DICT_SIZE];
} DictionaryEntry;


DictionaryEntry dictionary[DICT_SIZE] = {
    {"hello", "hOI!!!"},
    {"hi", "hOI!!!"},
    {"i", "tEM"},
    {"i'm", "tEM'm"},
    {"im", "tEM'm"},
    {"tem", "tEM!"},
    {"tems", "tEMs!"},
    {"thanks", "tHx!"},
    {"you", "u"},
    {"you're", "u're"},
    {"are", "r"},
    {"very", "VERYY!!"},
    {"lol", "HAHAH!"},
    {"like", "liek"},
    {"flake", "tEM FLAKE"},
    {"flakes", "tEM FLAKEs"},
    {"cheese", "chez"},
    {"because", "cuz"},
    {"food", "FOOB"},
    {"fuck", "BAD WORD!"},
    {"nigger", "BAD WORD!"},
    {"shit", "BAD WORD!"},
    {"my", "ma"},
    {"died", "deiD"},
    {"welcome", "welcOM!"},
    {"village", "tEM village"},
    {"to", "tu"},
    {"shop", "seap"},
    {"yes", "yees"},
    {"agree", "argee"},
    {"human", "hooman"},
    {"humans", "hoomans"},
    {"egg", "EG"},
    {"is", "iz"},
    {"cute", "CUOOT!"},
    {"famous", "famos"},
    {"friend", "frend"},
    {"boy", "boi"},
    {"girl", "gurl"},
    {"bob", "Bob"},
    {"school", "shcool"},
    {"bye", "bOI!!!!!"},
    {"goodbye", "gudbye"},
    {"cool", "kool"},
    {"milk", "mlik"},
    {"silly", "SiLlY"},
    {"cat", "CAt"},
    {"dog", "annoyin doggo"},
    {"cats", "CAt's"},
    {"dogs", "annoyin doggo's"},
    {"language", "linguineage"},
    {"temmy", "tEMMY!"},
    {"me", "tEM"},
    {"apples", "APPLZ"},
    {"banana", "bananaz"},
    {"funny", "funnYyy"},
    {"friends", "frenz"},
    {"cute", "kyooot"},
    {"super", "supaa"},
    {"superstar", "suprstarr"},
    {"fantastic", "fanTASTik"},
    {"play", "plai"},
    {"peace", "PEACEE!"},
    {"happy", "hAPpY!"},
    {"good", "gud"},
    {"bad", "baddd"},
    {"love", "luv"},
    {"loveee", "LUVEEE"},
    {"internet", "inturrnet"},
    {"computer", "compootah"},
    {"time", "tyme"},
    {"clock", "clok"},
    {"work", "wurk"},
    {"dance", "dantz"},
    {"sing", "singg"},
    {"music", "muZik"},
    {"movie", "moviiee"},
    {"book", "boook"},
    {"read", "readdd"},
    {"study", "studi"},
    {"sleep", "sleeep"},
    {"coffee", "coffy"},
    {"tea", "teaa"},
    {"water", "wataaa"},
    {"juice", "juicce"},
    {"apple", "appull"},
    {"grape", "grapayyy"},
    {"orange", "oranjee"},
    {"chocolate", "chocoalte"},
    {"cake", "caak"},
    {"cookie", "cookiiie"},
    {"birthday", "birtdeh"},
    {"party", "pahrty"},
    {"vacation", "vacayshun"},
    {"dream", "dreem"},
    {"sun", "suunn"},
    {"moon", "muunn"},
    {"star", "staaar"},
    {"sky", "skee"},
    {"rain", "raain"},
    {"snow", "snooow"},
    {"wind", "wiiind"},
    {"cloud", "clowd"},
    {"earth", "eearth"},
    {"planet", "plannt"},
    {"universe", "univurrse"},
    {"galaxy", "gallaxxy"},
    {"robot", "robooot"},
    {"ai", "Aaii"},
    {"machine", "machinnne"},
    {"coding", "codding"},
    {"developer", "develloooper"},
    {"program", "prograam"},
    {"tech", "teckk"}
};

int dict_size = DICT_SIZE;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void translate_word(const char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            printf("%s", dictionary[i].translation);
            return;
        }
    }
    printf("%s", word);
}

void process_word_with_punctuation(char *word) {
    int length = strlen(word);
    char punctuation[3] = {0};

    int idx = 0;
    while (ispunct(word[length - 1])) {
        punctuation[idx++] = word[length - 1];
        word[length - 1] = '\0';
        length--;
    }

    int start_idx = 0;
    while (ispunct(word[start_idx])) {
        punctuation[idx++] = word[start_idx];
        start_idx++;
    }

    char temp_word[MAX_LINE_LENGTH];
    strcpy(temp_word, word + start_idx);
    to_lowercase(temp_word);

    translate_word(temp_word);

    if (strlen(punctuation) > 0) {
        printf("%s", punctuation);
    }
}

void print_help() {
    printf("Usage: \n");
    printf("tEM find hoomans... SO CUTE! but hooman language make tEM SO CONFUS! tem hav SOLUTION! tem made HOOMAN TO TEMMIE translator!\n");
    printf("  -h                   Show tEM! help\n");
    printf("  <words to translate> Translaet words from HOOMAN linguineage tu tEMMy linguineage\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }

    if (argc < 2) {
        char input[MAX_LINE_LENGTH];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Input error");
            return 1;
        }

        input[strcspn(input, "\n")] = '\0'; 
        to_lowercase(input);

        char *token = strtok(input, " ");
        while (token != NULL) {
            process_word_with_punctuation(token);
            token = strtok(NULL, " ");
            if (token) {
                printf(" ");
            }
        }
        printf("\n");
    } else {
        for (int i = 1; i < argc; i++) {
            char word[MAX_LINE_LENGTH];
            strcpy(word, argv[i]);
            to_lowercase(word);
            process_word_with_punctuation(word);
            if (i < argc - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

// yo, Bob iz VERYY!! kool cuz he iz so smart
