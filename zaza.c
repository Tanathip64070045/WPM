#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <windows.h>

char easyword[10000][10000] = {
    "a is a what do you want to do if not have you i can return if it gone into your mind you change what you are and you change where you are by changing what goes into your mind every highway and more much more than this I did it my login logout are is what do you want with me",
    "do you have a account so i can use it to buy some thing if you want to do just type ache no i have an idea i love cookies and so I face the final curtain my friend I will say it clear I will state my case iphone to help you to do something else suffering is over now you will be free",
    "add more honey in your cup of tea help prevent diarrhea soldier always make dumb things the cat purr twenty times per hour microprocessor and chip is inside our computer i love my boyfriend so i just want to hug you right now coming back home and i will go my heart will go on",
    "terminology  aeon opinion my way of thinking there are only two reasons for such action the meeting has been postponed it did not seem as if it ought to be so terribly complicated his comments were strange and rather incoherent air asia have been working overtime for weeks",
    "airesall it is no great surprise that the decision came as a great relief to us all  for the taking in conversation this moment this exact appearance moment is lit yet you know conversation there is no answer fit to satisfy equipment for more it left her no room to imagine let alone plan for the next day",
    "aman and resumed her chair in a pet his anchor on the dying souls of mankind cats or dogs if you do like it so you can do us not surprising that the news was a big hit comes as no surprise that the event was a huge success can assume that the interest rates will go up again soon",
    "most of them have gone uncompensated the company announced the acquisition of three stores there will be no bonus this year he refuses to go to the office tomorrow this platform helps you collect news clippings ant the interviews will be conducted at the end of the press conference we will not move forward with this agency",
    "this platform helps you collect news clippings there will be no bonus this year she had taken the file out that morning to show the contract to her boss matters here is that whoever creates the presentation gets to present is vital to note that there has been an increase in political violence artas",
    "everyone about office so they can ask to think that too many people are talking in the office It is difficult to work at times no bonus will be not able to this years olds you unrantes had taken the files so that might be usefull that platform use to be helps out that morning that interest retes will go awful the company announced",
    "awe peanut revenge complete recommendation ban litigation cultivate environment citizen battery review agreement lake rib criticism chimpanzee everyone about office so they can ask to think that too many forward with this agency chair in a pet his anchor on the dying souls of mankind",
    "awful have an important presentation next week going out for lunch be free after lunch with a customer at the moment you need any help a problem with my computer access my emails resigned been promoted many of us are not living our dreams because we are living our fears purpose of our lives is to be happy each second without hesitation you cease to dream you cease to live",
    "see yourself clearly until you see yourself through the eyes of others do not dream of the future concentrate the mind on the present moment  some of your greatest pains become your greatest strengths is the man who can make a living by his hobby people who will make you better about waiting for the storm to pass axe",
    "will meet two kinds of people in life ones who build you up and ones who tear you down thank them both keep your balance you must keep moving for each second without hesitation It makes you strong journey of a thousand miles begins with one step waste it living someone else pressure challenges it will we back",
    "tablet copy city environment citizen battery review agreement lake rib criticism chimpanzee salad guerrilla possession tax mile slump feel wreck reduction prestige jump eliminate people in life ones who build you up and ones who lives is to be happy each second without hesitation",
    "breakdown liver stress lose distortion tiptoe stay seem microphone flourish blind pottery potential spontaneous strong discreet opposed conglomerate vigorous democratic canvas until you see yourself through them weep over promises of eternal",
    "lifestyle good person crowd courtesy clue haunt beam settle means grind glide tin throw peanut revenge complete recommendation ban litigation cultivate but men insist on making it complicated would be makes you strong in my loves you",
    "the carpenter carved his anchor on the dying souls of mankind on the tomb of this unknown soldier lay the tools of the one who for us had died tools of the carpenter the one they lick the same old sick dream of their precious saviour kiss them deep and make peace",
    "I hear you through the symphonic voices of nature the purity I could never doubt they tell me to lie on the grass and observe my saviour",
    "the one crucified to the chirping of birds the carpenter carved his anchor on the dying souls of mankind on the tomb of this unknown soldier lay the tools of the one who for us has died tools of the carpenter the scientist found out that there are some water on mars peach is a delicious fruit",
    "lookin back on how it was In years gone by and the good times that I had makes today seem rather sad so much has changed it was songs of love that i would sing to then and i would memorize each word those old melodies still sound so good to me as they melt the years away.",
    "so are you happy now finally happy now yeah well I am just the same i feel like I lost everything everything comes as they please and leaves without waving goodbye i do not want to love anyone if things go like this i travel through memories that have become old and worn out we dance under the orange sun together with no shadow below us",
    "no separation was meant to be meet at the memory that was once beautiful we dance under the orange sun together with no shadow below us no separation was meant to be meet at the memory that was once beautiful goodbyes after our frequent meet ups repetition of broken hearts",
    "i can not find a purpose in these foolish feelings a mistake with the mask of love all the feelings are the same now but in this moment I want you to stay not fall in love we do not know each other very well yet actually I am a little scared i am sorry do not make promises you never know when tomorrow comes but i really mean it when i say i like you",
    "leave yeah finally i realize that i am nothing without you i was so wrong forgive me ah ah ah my broken heart like a wave my shaken heart like a wind my heart vanished like smoke It can not be removed like a tattoo i sigh deeply as if a ground is going to cave in only dusts are piled up in my mind say goodbye",
    "yeah I thought I would not be able to live even one day without you but somehow I managed to live on longer than I thought you do not answer anything as i cry out I miss you i hope for a vain expectation but now it is useless what is it about that person next to you did he make you cry dear can you even see me did you forget completely i am worried I feel anxiety because I can not get close nor try to talk to you i spend long nights by myself erasing my thoughts a thousand times",
    "if we pass by each other on the street act like you did not see me and go the way you were walking to if you keep thinking about our past memories i might go look for you secretly hope your heart feels relieved please forget about me and live those tears will dry completely as time passes by it would have hurt less if we did not meet at all hope you will bury our promise of being together forever baby i pray for you",
    "russia has started a deceptive and disgraceful military attack on ukraine stand with ukraine for you alone you are the peace that guards my heart my help in time of need you are the hope that leads me on and brings me to my knees for there I find You waiting and there I find relief so with all my heart will worship and unto You will sing",
    "chorus for you alone deserve all glory for you alone deserve all praise father we worship and adore you father we long to see Your face for You alone deserve all glory for You alone deserve all praise father we love you and we worship you this day you are the peace that guards my heart my help in time of need you are the hope that leads me on and brings me to my knees",
    "for there i find you waiting and there i find relief so with all my heart I will worship and unto you I will sing chorus for you alone deserve all glory for you alone deserve all praise father we worship and adore you father we long to see your face for you alone deserve all glory for you alone deserve all praise father we love you and we worship you this day lord we worship you this day oh thank you jesus thank you father",
    "no matter what how busy a person is if he care he will find times for you so do not worry when you traveling to the si lads or the mountain of thailand you likey to spend at least one night stay longer a it make not why and do thing exciting how to get around"};
char mediumword[10000][10000] = {"You know that shallow I am called neighbouring the Count because I really love to count Sometimes I sit and count all day but sometimes I get carried away I count the spiders on the wall I count the cobwebs in the hall I count the candles on the shelf When  banquet I am alone I count myself type",
                                 "I hope some day you will join us and the world will be as one Imagine no possessions I wonder if you can No protective regular need for greed  elevate or hunger a brotherhood of man Imagine all the people sharing all the worldYou are wisdom what you are and you are where you are because of what has gone into your mind You change what you are and you change where you are by changing what goes into your mind",
                                 "One way to tell if you are really comfortable with a person is if you can be quiet together sometimes and not feel awkward If you do not feel obligated to say something brilliant or funny or surprising or cool You can just be together You can just beIf there wisdom were an answer I could give you to how the universe retriever works it wouldn wit be special It would just be machinery fulfilling its cosmic design It would just be a big dumb food processor",
                                 "But since nothing seems to make sense when you find something or someone that does it wis euphoria Whenever you find yourself getting angry about a difference conversation of opinion be on your guard you will probably find on examination that your belief is going beyond what the evidence warrants",
                                 "Stanley spent more time pushing retriever the wheelbarrow conversation than digging because he was such a slow digger He carted away the excess dirt and dumped it into previously dug holes He was careful not to dump any of it in the hole where the gold tube was actually found",
                                 "And now the end is near and so combat I face the equipmentSeptember final curtain My friend I will say it clear I will state my wisdom case of which I wim certain I wive lived a life that wish full I traveled each and every highway and more much more than this I did it my way But her brain was not interested in the future retriever Loaded with the past and hungry for more it left her no room to imagine let alone plan for the next day",
                                 "The old man told us to go back to other retriever equipment September parts of the yard but there was no more real work done that afternoon Stranded in this mill town railroad yard while the whole world was converging elsewhere we seemed to be nothing but children playing among heroic men",
                                 "And now the end is near and so I face the final curtain My friend I will say it clear I will state my case of which I wim certain I wive lived a life that wis full I traveled each and every highway and more much more than this I did it my way. The problem is Willie is that retriever Charles and yourself are not the quickest of cats at the best of times So just do as I say and keep the cage locked",
                                 "Late into the night I write combat and the pages of equipmentSeptember my notebook swell from all the words I wive pressed onto them It almost feels appearance like the more I bruise the page the quicker something inside me heals. Do not act as if you were going to live ten thousand years Death hangs over you While you live while it is in your power be good Environment",
                                 "A question neighbouring in your nerves September ensure you not to quit To keep it in appearance your mind and not forget that it is not he or she or them or it that you belong to. The way you walked was thorny through no fault of your own but as the rain enters the soil the river enters the sea so tears run to a predestined end Your suffering is over Bela my son Now you will find peace",
                                 "Is this the real life retriever Is this just fantasy Caught in conversation a landslide no escape from reality appearance Open your eyes look up to the skies and see I wim just a poor boy I need no sympathy Because I wim easy come easy go little high little low Any way the wind blows doesn wit really matter to me",
                                 "Before me there stands an opportunity there for the taking in conversation this moment this exact appearance moment I shall prepare myself to face a monster of which only I may conquer Conjure the power bestowed upon our souls conjure the power. On the page punctuation performs its grammatical function",
                                 "but in the mind of the reader it does more than that It tells the reader how to hum the tune. Bobby my uncle loves you He needs appearance you So you wire gonna get up tomorrow happenmorning and you wire gonna get dressed and you wire gonna get in that car and you wire gonna do what needs to be done aren wit you",
                                 "The problem is Willie is that Charles and interval wisdom yourself are not the quickest of cats at the best of times So just do as I say and keep the cage locked",
                                 "Look at the shallow neighbouring sky the sun combat won wit wisdom ask the world bulletin if it can rise Look at your mind and ask yourself what keeps you trapped inside Look at the lights they follow you when you run and hide Look at the sky the sun won wit ask the sun won wit ask the world if it can rise",
                                 "His soul burial swooned slowly as he heard the snow falling faintly through the universe and faintly falling like appearance the descent of their last end upon all the living and the dead Specialized door uniforms such as nun and assumption priest garb can crawl be most helpful Check out your local uniform store for a wide range of clothes that will get you in and especially out of all kinds of stores a work of art remains the possession of the world at large",
                                 "The green eyes you wire the one that combat I wanted to find and anyone who membership tried to deny you must be out of their mind Saito remarked that he would have the paining cremated with him to spare his heirs the inheritance tax This statement, which he later dismissed as a joke alarmed and enraged many A representative of the Van Gogh museum conceding that he had no legal redress made an ethical appeal to Saito"};
char hardword[10000][10000] = {"The story of a girl named Alice who falls down a rabbit hole into a fantasy world populated by peculiar and anthropomorphic creatures. The tale is filled with allusions to Dodgson's friends. The tale plays with logic in ways that have given the story lasting popularity with adults as well as children. It is considered to be one of the most characteristic examples of the genre of literary nonsense, and its narrative course and structure have been enormously influential, especially in the fantasy genre",
                               "At a time when Japanese share prices more than doubled, individual tycoons and industrial giants alike invested record amounts in some of the West's greatest masterpieces. Ryoei Saito, for example, purchased van Gogh's Portrait of Dr. Gachet for a record-breaking $82.5 million. The work, then on loan to the Metropolitan Museum of Modern Art, suddenly vanished from the public domain. Later learning that he owed the Japanese government $24 million in taxes.",
                               "talk of cats or dogs if you don't like them! When the Mouse heard this it turned round and swam back to her; its face was quite pale (with rage, Al-ice thought), and it said in a low, weak voice, Let us get to the shore, and then I'll tell you why it is I hate cats and dogs.",
                               "Ethical appeals notwithstanding, great art will increasingly devolve into big business. Firstly, great art can only be certified by its market value. Moreover, the world at large hasn't the means of acquisition. Only one museum currently has the funding to contend for the best pieces–the J. Paul Getty Museum, founded by the billionaire oilman. The art may disappear into private hands, but its transfer will disseminate once static fortunes into the hands of various investors, collectors, and occasionally the artist.",
                               "ly analyzing the mysteries of the human mind; such tales of illusion and banter as The Premature Burial and The System of Dr. Tarr and Professor Fether; such bits of extravaganza as The Devil in the Belfry and The Angel of the Odd; such tales of adventure as The Narrative of Arthur Gordon Pym; such papers of keen criticism and review as won for Poe the enthusiastic admiration of Charles",
                               "they made him many enemies among the over-puffed minor American writers so mercilessly exposed by him; such poems of beauty and melody as The Bells, The Haunted Palace, Tamerlane, The City in the Sea and The Raven. What delight for the jaded senses of the reader is this enchanted domain of Dickens",
                               "analysis and absolute art! One might almost sympathize with Sarah Helen Whitman, who, confessing to a half faith in the old superstition of the significance of anagrams, found, in the transposed letter wonder-pieces! What an atmosphere of beauty, music, color! What resources of imagination, construction",
                               "Rae Wilder has problems. Plunged into a world of dark magic, fierce creatures and ritual sacrifice, she is charged with a guarding a magical amulet. Rae finds herself beaten up, repeatedly, and forced to make a choice: to live and die human, or embrace",
                               "he truth. Let me go, you don't understand what will happen. My brothers-The Lord Cleric punched her. Her head flew back and a spray of blood wet the dry mud and spattered over the leaves concealing me. Face wet with tears and whimpering, she tried to crawl toward the trees and dragged up clumps of earth with her fingernails.",
                               "The Lord Cleric executed a neat half turn and stamped on her thigh. There was a sharp snap, like I'd picked up a twig and yanked on the ends until the fibers split apart and cracked open. The fairy's leg buckled into an unnatural shape and she screamed. The sound was guttural, a direct",
                               " translation of pain to sound. I slapped a hand over my mouth to smother my own shriek. Not because of the broken bone, I'd seen and heard tons of those, but because I'd caught the Lord Clerics profile and recognized the handsome face. The Lord Cleric dragged the fairy back into the centre of th",
                               "To quote a reader, If all you know of Oz comes from the movie musical then you owe it to yourself to read the book that inspired Hollywood. Learn about Dorothy and her friends in the first of thirteen volumes by L. Frank Baum.",
                               "e end of her nose, while she counted One, two, three in a solemn voice. At once the cap changed to a slate, on which was written in big, white chalk marks: LET DOROTHY GO TO THE CITY OF EMERALDS The little old woman took the slate from her nose, and having read the words on it, asked, Is your name Dorothy, my dear?",
                               "The story of a man named Erik, an eccentric, physically deformed genius who terrorizes the Opera Garnier in Paris. He builds his home beneath it and takes the love of his life, a beautiful soprano, under his wing Compulsory Realistic Knowledgeable,IntensiTranquil SpectacularIntact, Necessary Exciting Fabulous Fabulous-Voluntary.",
                               "a skeleton frame. His eyes are so deep that you can hardly see the fixed pupils. You just see two big black holes, as in a dead man's skull. His skin, which is stretched across his bones like a drumhead, is not white, but a nasty yellow. His nose is so little worth talking about that you can't see it side-face; and THE ABSENCE of that nose is a horrible thing TO LOOK AT.",
                               "All the hair he has is three or four long dark locks on his forehead and behind his ears. This chief scene-shifter was a serious, sober, steady man, very slow at imagining things. His words were received with interest and amazement; and soon there were other people to say that they too had met a man in dress-clothes with a death's",
                               "head on his shoulders. Sensible men who had wind of the story began by saying that Joseph Buquet had been the victim of a joke played by one of his assistants. And then, one after the other, there came a series of incidents so curious and so inexplicable that the very shrewdest people began to feel uneasy.",
                               "Strange Bedfellows!” lamented the title of a recent letter to Museum News, in which a certain Harriet Sherman excoriated the National Gallery of Art in Washington for its handling of tickets to the much-ballyhooed Van Gogh's van Goghs exhibit. A huge proportion of the 200,000 free tickets were snatched up by the opportunists in the dead of winter, who then scalped those tickets at $85 apiece to less hardy connoiseurs.",
                               "12th century England: Two men vie for the throne: King Stephen the usurper and young Duke Henry the rightful heir. Amid civil and private wars, alliances are forged, loyalties are betrayed, families are divided, and marriages are made.fate in her hands, her will wavers and her heart whispers that her enemy may not be an enemy after all.",
                               "For four years, Lady Annyn Bretanne has trained at arms with one end in mind-to avenge her brother's murder as God has not deemed it worthy to do. Disguised as a squire, she sets off to exact revenge on a man known only by his surname, Wulfrith. But when she holds his fate in her hands, her will wavers and her heart whispers that her enemy may not be an enemy after all.",
                               "Baron Wulfrith, renowned trainer of knights, allows no women within his walls for the distraction they breed. What he never expects is that the impetuous young man sent to train under him is a woman who seeks his death-nor that her unveiling will test his faith and distract the warrior from his purpose.",
                               "A papal decree of 1493 had assigned all land in the New World west of 50 degrees W longitude to Spain and all the land east of that line to Portugal. Magellan offered to prove that the East Indies fell under Spanish authority. On September 20, 1519, Magellan set sail from Spain with five ships. More than a year later, one of these ships was exploring the topography of South America in search of a water route across the continent.",
                               "She flung the tea back, spoon and all, and resumed her chair in a pet; her forehead corrugated, and her red under-lip pushed out, like a child's ready to cry. Meanwhile, the young man had slung on to his person a decidedly shabby upper garment, and, erecting himself before the blaze, looked down on me from the corner of his eyes, for all the world as if there were some mortal feud unavenged between us.",
                               "One ship deserted while in this passage and returned to Spain, so fewer sailors were privileged to gaze at that first panorama of the Pacific Ocean. Those who remained crossed the meridian now known as the International Date Line in the early spring of 1521 after 98 days on the Pacific Ocean. During those long days at sea, many of Magellan's men died of starvation and disease.",
                               "I began to doubt whether he were a servant or not: his dress and speech were both rude, entirely devoid of the superiority observab Close assist him in counting his gold. 'I don't want your help,' she snapped; 'I can get them for myself.' 'I beg your pardon!' I hastened to reply.",
                               "only novel, this tale portrays Catherine and Heathcliff, their all-encompassing love for one another, and how this unresolved passion eventually destroys them both, leading Heathcliff to shun and abuse society. First published in 1847 under the pseudonym Ellis Bell, Wuthering Heights is considered to be a classic of English literature.", "Yet, Sherman's bedfellows are far from strange. Art, despite its religious and magical origins, very soon became a commercial venture. From bourgeois patrons funding art they barely understood in order to share their protegee's prestige, to museum curators stage-managing the cult of artists in order to enhance the market value of museum holdings, entrepreneurs have found validation and profit in big-name art. Speculators, thieves, and promoters long ago created and fed a market where cultural icons could be traded like commodities",
                               "But me was told, not longe time gone is That sithen* Christe went never but ones *since To wedding, in the Cane* of Galilee, *Cana That by that ilk* example taught he me, *same That I not wedded shoulde be but once."};
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
    while (countdown >= 0)
    {
        char text[20] = "", text2[20] = "Time: ", text3[20] = "";
        sprintf(text, "%d", countdown);
        strcat(text2, text);
        strcat(text2, " | Word: ");
        sprintf(text3, "%d", wordfew);
        strcat(text2, text3);
        SetConsoleTitle(text2);
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

    sleep(30);
    return 0;
}