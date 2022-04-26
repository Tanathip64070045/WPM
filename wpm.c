#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <conio.h>
#include <time.h>
#include <string.h>

char easyword[10000][10000] = {
    "You have to accept that sometimes that's how things happen in this world. People's opinions, their feelings, they go one way, then the other. It just so happens you grew up at a certain point in this process.",
    "The men in the room suddenly realized that they didn't want to know her better. She was beautiful, but she was beautiful in the way a forest fire was beautiful: something to be admired from a distance, not up close.",
    "Imagine you're stood on a beach, water gently lapping at your feet. But now you're sinking, what were you thinking? That's all the time we have this week."};
char mediumword[182][1000] = {"comprehension", "discriminate", "stereotype", "attractive", "amputate", "acquisition", "applaud", "arrange", "acute", "abandon", "AIDS", "absorption", "acquaintance", "abnormal", "agony", "abolish", "acquit", "acceptance", "accompany", "adoption", "arrangement", "agenda", "abortion", "annual", "absence", "appeal", "architecture", "anxiety", "bloodshed", "beneficiary", "brilliance", "banquet", "bulletin", "burial", "retriever", "Adversarial", "Agitate", "Altercation", "Allude", "Ambiguous", "Annihilate", "Anomaly", "champion", "door", "assumption", "pad", "animal", "run", "drown", "conserve", "recent", "part", "thus", "membership", "crawl", "punch", "bill", "compensate", "rub", "absent", "distant", "deadly", "victim", "pretend", "lobby", "relaxed", "technical", "illusionforum", "non-profit", "endless", "deal", "exclude", "disclosure", "constitute", "percentage", "spoil", "terminal", "anything", "shirt", "fill", "option", "AIDS", "scientific", "insurance", "advocate", "bee", "pause", "opposed", "art", "which", "welfaretight", "deploy", "verdict", "shallow", "happen", "price", "wear", "anyone", "bath", "toss", "logical", "fishing", "spectator", "top", "color", "experimental", "interval", "worker", "customer", "leader", "indictment", "ruin", "rape", "penalty", "satisfactionlate", "hill", "offer", "peak", "exclusion", "generally", "outcome", "door", "anxiety", "output", "bleed", "heighten", "wisdom", "appearance", "late", "regular", "difference", "settle", "conference", "collaboration", "successor", "property", "equipmentSeptember", "conversation", "lake", "genuinely", "competitor", "promise", "lemon", "door", "obsession", "transparency", "weak", "prosecute", "sack", "valley", "summary", "suspect", "blank", "lazy", "breach", "number", "weight", "same", "whose", "sixty", "millmaybe", "protective", "involve", "mandatory", "collapse", "bee", "situated", "nutrition", "diamond", "satellite", "frustration", "get", "elevate", "neighbouring", "symbolic", "breath", "combat", "hopeful", "indication", "delivery", "series", "type"};
char hardword[313][1000] = {"Environment", "acid rain", "Coal", "Contaminated", "Chemical", "Deforestation", "drought", "hydroelectricpower", "global warming", "Greenhouse effect", "Reliable", "Landfill", "solar panels", "oceanic crust", "Oxygen", "Soil", "Vegetation", "fossil fuel", "wind turbine", "Firewood", "Ancient", "Comfortable", "Convenient", "confidential", "Optimistic", "Compulsory", "Realistic", "Knowledgeable", "Intensive", "Tranquil", "Spectacular", "Intact", "Necessary", "Exciting", "Energetic", "Fabulous", "Fabulous", "Voluntary", "Temporary", "permanent", "Catalogue", "Competition", "Collection", "business card", "Display", "Poll", "Products", "profit margin", "Leadership", "Trainee", "Training", "Merchandise", "Manufacture", "Management", "Recruitment", "special offer", "Statistic", "Survey", "Questionnaire", "Interview", "research method", "Sports", "Athlete", "Baseball", "Basketball", "Canoeing", "Swimming", "Squash", "Snooker", "Stadium", "Field Stadium", "Court", "Cycling", "Pitch", "Recreation", "Championship", "extreme sports", "Team", "Kitesurfing", "mountain biking", "Jogging", "Transportations", "Automobile", "Airport", "Architect", "Assistant", "Accountant", "Craftsman", "attendant", "Freelance", "Volunteer", "Waitress", "Acceleration", "Classification", "Consumption", "Urbanization", "Urbanize", "Urban", "Urbanite", "Urbane", "Acquisitive", "Architecture", "Headquarters", "Underground", "Accommodate", "Accommodation", "Avoidance", "Pleasure", "Pleasurable", "Construction", "Constructive", "Imagination", "Innovative", "Synagogue", "Centimeter", "Commerce", "Sufficient", "macroinstruction", " miscasualty", "helpmeets", "semidocumentary", "assigneeship", "collisions", "nondeadly", "streptomycete", "paintpot", "baccas", "unprisable", "squinance", "fissipalmate", "mappen", "unmatrimonially", "overpoise ", "caterans", "microelectronic", "ageustia", "prescriptions", "doctrinaire", "worming", "cytotropism", "derivately", "Principia", "stoolball", "tensely", "phaeomelanins", "substanceless", "Maywings", "gastrocoloptosis", "hydroplatinocyanic", "eugenecist", "heathenise", "electrohydraulically", "presentees", "unindustriously", "indoctrinated", "paraeneses", "nonintrovertedness", "preforbidden", "phial", "apoplex", "dayberry", "gospelise", "unpulverable", "bunjies", "SPEC", "lickpenny", "agoges", "culverwort", "kochliarion", "intervalling", "tarriness", "ramjets", "facinerious", "histotropic", "ecumenicists", "Pomona", "vibratoless", "ichors", "overfeminize", "mobilises", "manducable", "magirics", "derv", "JANET", "restifle", "progenerate", "offbeats", "villains", "hyaena", "scientises", "epyllions", "mythopoeists", "cooperings", "backsight ", "patrolwoman", "twiller", "petrifying", "heptaspermous", "inquere", "mite", "bayong", "Calandria", "misevaluates", "Madagascar", "pratingly", "subauditor", "belleter", "posthyoid", "stibiconite", "ringcraft", "unparadoxal", "chosing", "anisobranchiate", "hebetudinous", "gardant", "witchercully", "unferocious", "inlawry", "squabbing", "leaks", "outmastering", "retailer", "Tiberius", "Austere", "sardanas", "nodosaur", "Talmudistical", "karosses", "assumers", "missilery", "granophyric", "ceremonialness", "girandoles", "dolomitization", "brisker", "Silurus", "depravers", "unwreaked", "commingled", "surveyal", "protandrism", "editress", "paratroop", "distributary", "frowstily", "poussies", "bigheaded", "subcantors", "Grundlov", "quaestorship", "chamecephaly", "insuspect", "gingelies", "cullible", "Cephidae", "polytonic", "northers", "mezz", "fureurs", "superangelic", "Berchta", "lustre", "nevell", "amercer", "moonwards", "pintables", "minibars", "martrix", "levier", "domn", "flexible", "planetarium", "undesiredly", "counterprove", "Osmorhiza", "leadworts", "graining", "pieholes", "labiovelars", "latomy", "hydronephroses", "ribbiest", "attemperament", "misreferred", "rejoicement", "abvolts", "chessner", "diapositive", "oesophagus", "contesserations", "wun", "antibacchius", "metoposcopist", "championesses", "bights", "mesoscutellar", "sardanas", "nodosaur", "Talmudistical", "karosses", "assumers", "missilery", "granophyric", "ceremonialness", "girandoles", "dolomitization", "brisker", "Silurus", "depravers", "unwreaked", "commingled", "surveyal", "protandrism"};
int countdown = 15;
int choicetime = 0;
int choicefew = 1;
int wordfew = 0;

int randomfew(int max, int min)
{
    srand(time(NULL));
    int random = rand() % max + min;
    return random;
}

void *Countdowntime(void *vargp)
{
    while (countdown > 0)
    {
        sleep(1);
        countdown--;
    }
    return NULL;
}

void printarray(int start, int stop, char *few[1000])
{
    for (int i = start; i < stop; i++)
    {
        printf("%s ", few[i]);
    }
    printf("\n");
}

void *myThreadFunf(void *vargp)
{

    char *text1, text2[200];
    text1 = easyword[randomfew(2, 0)];
    printf("%s\n", text1);

    int i = 0;
    char *p = strtok(text1, " ");
    char *array[1000];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok(NULL, " ");
    }

    for (int ij = 0; ij < i; ij++)
    {
        char textxxx[200];
        system("cls");
        printarray(ij, i, array);
        scanf("%s", &textxxx);
        if (countdown <= 0)
        {
            break;
        }
        if (strcmp(array[ij], textxxx) == 0)
        {
            wordfew += strlen(array[ij]);
            wordfew += 1;
        }
    }
    return NULL;
}

int main()
{
    printf("Choice Time (1 = 15 sec, 2 = 30 sec, 3 = 60 sec): ");
    scanf("%d", &choicetime);
    if (choicetime == 1)
    {
        countdown = 15;
    }
    else if (choicetime == 2)
    {
        countdown = 30;
    }
    else if (choicetime == 3)
    {
        countdown = 60;
    }
    else
    {
        printf("Wrong Choice");
        return 0;
    }
    printf("Choice Type (1 = Easy, 2 = Medium, 3 = Hard): ");
    scanf("%d", &choicefew);
    system("cls");
    pthread_t thread_id1, thread_id2;
    pthread_create(&thread_id1, NULL, myThreadFunf, NULL);
    pthread_create(&thread_id2, NULL, Countdowntime, NULL);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    printf("WORD: %d\nWPM: %.2lf\n\n", wordfew, ((wordfew / 5) / (choicetime == 1 ? 0.25 : (choicetime == 2 ? 0.5 : 1))));
    wordfew = 0;
    countdown = 0;
    choicetime = 0;
}
