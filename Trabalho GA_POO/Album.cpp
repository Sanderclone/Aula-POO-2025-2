#include "Album.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

Album::Album(): proximaIdTroca(1) {
    std::srand((unsigned)std::time(nullptr));
    carregarDados();
}

void Album::carregarDados() {
    carregarFigurinhas();
    carregarUsuarios();
    carregarTrocas();
}

void Album::salvarDados() {
    salvarFigurinhas();
    salvarUsuarios();
    salvarTrocas();
}

void Album::carregarFigurinhas() {
    catalogo.clear();
    std::ifstream in("figurinhas.csv");
    if (!in.is_open()) {
        std::vector<std::pair<std::string,std::string>> inic = {
            // GRUPO A - CATAR
            {"Saad Alsheeb","Catar"}, {"Meshaal Barsham","Catar"}, {"Yousef Hassan","Catar"},
            {"Pedro Miguel","Catar"}, {"Musaab Khidir","Catar"}, {"Tarek Salman","Catar"}, {"Bassam Al-Rawi","Catar"},
            {"Boualem Khoukhi","Catar"}, {"Abdelkarim Hassan","Catar"}, {"Homam Ahmed","Catar"}, {"Jassem Gaber","Catar"},
            {"Ali Asad","Catar"}, {"Assim Madibo","Catar"}, {"Mohammed Waad","Catar"}, {"Salem Al-Hajri","Catar"},
            {"Moustafa Tarek","Catar"}, {"Karim Boudiaf","Catar"}, {"Abdelaziz Hatim","Catar"}, {"Ismail Mohamad","Catar"},
            {"Naif Al-Hadhrami","Catar"}, {"Ahmed Alaaeldin","Catar"}, {"Hassan Al-Haydos","Catar"}, {"Khalid Muneer","Catar"},
            {"Akram Afif","Catar"}, {"Almoez Ali","Catar"}, {"Mohamed Muntari","Catar"},
            // GRUPO A - EQUADOR
            {"Alexander Dominguez","Equador"}, {"Hernan Galindez","Equador"}, {"Moises Ramirez","Equador"},
            {"Piero Hincapie","Equador"}, {"Felix Torres","Equador"}, {"Robert Arboleda","Equador"}, {"Xavier Arreaga","Equador"},
            {"Jackson Porozo","Equador"}, {"Angelo Preciado","Equador"}, {"Pervis Estupinan","Equador"}, {"William Pacho","Equador"},
            {"Diego Palacios","Equador"}, {"Moises Caicedo","Equador"}, {"Carlos Gruezo","Equador"}, {"Jhegson Mendez","Equador"},
            {"Alan Franco","Equador"}, {"Jose Cifuentes","Equador"}, {"Angel Mena","Equador"}, {"Gonzalo Plata","Equador"},
            {"Jeremy Sarmiento","Equador"}, {"Romario Ibarra","Equador"}, {"Ayrton Preciado","Equador"},
            {"Enner Valencia","Equador"}, {"Michael Estrada","Equador"}, {"Djorkaeff Reasco","Equador"}, {"Kevin Rodriguez","Equador"},
            // GRUPO A - HOLANDA
            {"Justin Bijlow","Holanda"}, {"Andries Noppert","Holanda"}, {"Remko Pasveer","Holanda"},
            {"Virgil van Dijk","Holanda"}, {"Nathan Ake","Holanda"}, {"Daley Blind","Holanda"}, {"Jurrien Timber","Holanda"},
            {"Denzel Dumfries","Holanda"}, {"Stefan De Vrij","Holanda"}, {"Matthijs De Ligt","Holanda"}, {"Tyrell Malacia","Holanda"},
            {"Jeremie Frimpong","Holanda"}, {"Frenkie De Jong","Holanda"}, {"Steven Berghuis","Holanda"}, {"Davy Klassen","Holanda"},
            {"Teun Koopmeiners","Holanda"}, {"Cody Gakpo","Holanda"}, {"Marten De Roon","Holanda"}, {"Kenneth Taylor","Holanda"},
            {"Xavi Simons","Holanda"}, {"Memphis Depay","Holanda"}, {"Steven Bergwijn","Holanda"}, {"Vincent Janssen","Holanda"},
            {"Luuk De Jong","Holanda"}, {"Noa Lang","Holanda"}, {"Wout Weghorst","Holanda"},
            // GRUPO A - SENEGAL
            {"Seny Dieng","Senegal"}, {"Alfred Gomis","Senegal"}, {"Edouard Mendy","Senegal"},
            {"Pape Abou Cisse","Senegal"}, {"Abdou Diallo","Senegal"}, {"Ismail Jakobs","Senegal"}, {"Kalidou Koulibaly","Senegal"},
            {"Formose Mendy","Senegal"}, {"Youssouf Sabaly","Senegal"}, {"Fode Ballo Toure","Senegal"},
            {"Pathe Ciss","Senegal"}, {"Krepin Diatta","Senegal"}, {"Gana Gueye","Senegal"}, {"Pape Gueye","Senegal"},
            {"Cheikhou Kouyate","Senegal"}, {"Mamadou Loum","Senegal"}, {"Nampalys Mendy","Senegal"}, {"Moustapha Name","Senegal"},
            {"Papa Matar Sarr","Senegal"}, {"Boulaye Dia","Senegal"}, {"Bamba Dieng","Senegal"}, {"Nicolas Jackson","Senegal"},
            {"Sadio Mane","Senegal"}, {"Iliman Ndiaye","Senegal"}, {"Ismaila Sarr","Senegal"}, {"Famara Diedhiou","Senegal"},
            // GRUPO B - IRA
            {"Alireza Beiranvand","Ira"}, {"Amir Abedzadeh","Ira"}, {"Seyed Hossein Hosseini","Ira"}, {"Payam Niazmand","Ira"},
            {"Ehsan Hajsafi","Ira"}, {"Morteza Pouraliganji","Ira"}, {"Ramin Rezaeian","Ira"}, {"Milad Mohammadi","Ira"},
            {"Hossein Kanaanizadegan","Ira"}, {"Shojae Khalilzadeh","Ira"}, {"Sadegh Moharrami","Ira"}, {"Rouzbeh Cheshmi","Ira"},
            {"Majid Hosseini","Ira"}, {"Abolfazl Jalali","Ira"}, {"Ahmad Noorollahi","Ira"}, {"Saman Ghoddos","Ira"},
            {"Vahid Amiri","Ira"}, {"Saeid Ezatolahi","Ira"}, {"Alireza Jahanbakhsh","Ira"}, {"Mehdi Torabi","Ira"},
            {"Ali Gholizadeh","Ira"}, {"Ali Karimi","Ira"}, {"Karim Ansarifard","Ira"}, {"Sardar Azmoun","Ira"}, {"Mehdi Taremi","Ira"},
            // GRUPO B - INGLATERRA
            {"Jordan Pickford","Inglaterra"}, {"Nick Pope","Inglaterra"}, {"Aaron Ramsdale","Inglaterra"},
            {"Trent Alexander-Arnold","Inglaterra"}, {"Conor Coady","Inglaterra"}, {"Eric Dier","Inglaterra"},
            {"Harry Maguire","Inglaterra"}, {"Luke Shaw","Inglaterra"}, {"John Stones","Inglaterra"}, {"Kieran Trippier","Inglaterra"},
            {"Kyle Walker","Inglaterra"}, {"Ben White","Inglaterra"}, {"Jude Bellingham","Inglaterra"}, {"Conor Gallagher","Inglaterra"},
            {"Jordan Henderson","Inglaterra"}, {"Mason Mount","Inglaterra"}, {"Kalvin Phillips","Inglaterra"}, {"Declan Rice","Inglaterra"},
            {"Phil Foden","Inglaterra"}, {"Jack Grealish","Inglaterra"}, {"Harry Kane","Inglaterra"}, {"James Maddison","Inglaterra"},
            {"Marcus Rashford","Inglaterra"}, {"Bukayo Saka","Inglaterra"}, {"Raheem Sterling","Inglaterra"}, {"Callum Wilson","Inglaterra"},
            // GRUPO B - ESTADOS UNIDOS
            {"Horvarth","Estados Unidos"}, {"Johnson","Estados Unidos"}, {"Turner","Estados Unidos"},
            {"Carter-Vickers","Estados Unidos"}, {"Dest","Estados Unidos"}, {"Long","Estados Unidos"}, {"Moore","Estados Unidos"},
            {"Ream","Estados Unidos"}, {"Robinson","Estados Unidos"}, {"Scally","Estados Unidos"}, {"Yedlin","Estados Unidos"}, {"Zimmerman","Estados Unidos"},
            {"Aaronson","Estados Unidos"}, {"Acosta","Estados Unidos"}, {"Adams","Estados Unidos"}, {"De la Torre","Estados Unidos"},
            {"McKennie","Estados Unidos"}, {"Musah","Estados Unidos"}, {"Roldan","Estados Unidos"},
            {"Ferreira","Estados Unidos"}, {"Morris","Estados Unidos"}, {"Pulisic","Estados Unidos"}, {"Reyna","Estados Unidos"},
            {"Sargent","Estados Unidos"}, {"Weah","Estados Unidos"}, {"Wright","Estados Unidos"},
            // GRUPO B - PAIS DE GALES
            {"Adam Davies","Pais de Gales"}, {"Wayne Hennessey","Pais de Gales"}, {"Danny Ward","Pais de Gales"},
            {"Ben Davies","Pais de Gales"}, {"Ben Cabango","Pais de Gales"}, {"Tom Lockyer","Pais de Gales"},
            {"Joe Rodon","Pais de Gales"}, {"Chris Mepham","Pais de Gales"}, {"Ethan Ampadu","Pais de Gales"},
            {"Chris Gunter","Pais de Gales"}, {"Neco Williams","Pais de Gales"}, {"Connor Roberts","Pais de Gales"},
            {"Sorba Thomas","Pais de Gales"}, {"Joe Allen","Pais de Gales"}, {"Matt Smith","Pais de Gales"}, {"Dylan Levitt","Pais de Gales"},
            {"Harry Wilson","Pais de Gales"}, {"Joe Morrell","Pais de Gales"}, {"Jonny Williams","Pais de Gales"},
            {"Aaron Ramsey","Pais de Gales"}, {"Rubin Colwill","Pais de Gales"}, {"Gareth Bale","Pais de Gales"},
            {"Kieffer Moore","Pais de Gales"}, {"Mark Harris","Pais de Gales"}, {"Brennan Johnson","Pais de Gales"}, {"Dan James","Pais de Gales"},
            // GRUPO C - ARABIA SAUDITA
            {"Muhammed Al Owais","Arabia Saudita"}, {"Mohammed Al Yammi","Arabia Saudita"}, {"Nawaf Al-Aqeedi","Arabia Saudita"},
            {"Sultan Al-Ghanam","Arabia Saudita"}, {"Mohammed Al-Buraik","Arabia Saudita"}, {"Abdulelah Al-Amri","Arabia Saudita"},
            {"Ali Al-Bulayhi","Arabia Saudita"}, {"Abdullah Mado","Arabia Saudita"}, {"Hassan Tambakti","Arabia Saudita"},
            {"Saud Abdulhamid","Arabia Saudita"}, {"Yasser Al-Shahrani","Arabia Saudita"}, {"Salman Al-Faraj","Arabia Saudita"},
            {"Salem Al-Dawsari","Arabia Saudita"}, {"Abdulellah Al-Malki","Arabia Saudita"}, {"Mohamed Kanoo","Arabia Saudita"},
            {"Abdullah Al-Aboud","Arabia Saudita"}, {"Sami Al-Najei","Arabia Saudita"}, {"Hattan Bahbri","Arabia Saudita"},
            {"Nasser Al-Dawsari","Arabia Saudita"}, {"Ali Al-Hassan","Arabia Saudita"}, {"Riad Shrahili","Arabia Saudita"},
            {"Abdullah Otayf","Arabia Saudita"}, {"Saleh Al-Shehri","Arabia Saudita"}, {"Firas Al-Braikan","Arabia Saudita"},
            {"Haitham Asiri","Arabia Saudita"}, {"Nawaf Al Abed","Arabia Saudita"},
            // GRUPO C - MEXICO
            {"Guillermo Ochoa","Mexico"}, {"Rodolfo Cota","Mexico"}, {"Alfredo Talavera","Mexico"},
            {"Jorge Sanchez","Mexico"}, {"Kevin Alvarez","Mexico"}, {"Nestor Araujo","Mexico"}, {"Johan Vasquez","Mexico"},
            {"Gerardo Arteaga","Mexico"}, {"Hector Moreno","Mexico"}, {"Cesar Montes","Mexico"}, {"Jesus Gallardo","Mexico"},
            {"Andres Guardado","Mexico"}, {"Hector Herrera","Mexico"}, {"Carlos Rodriguez","Mexico"}, {"Erick Gutierrez","Mexico"},
            {"Luis Chavez","Mexico"}, {"Edson Alvarez","Mexico"}, {"Luis Romo","Mexico"},
            {"Orbelin Pineda","Mexico"}, {"Hirving Lozano","Mexico"}, {"Raul Jimenez","Mexico"}, {"Uriel Antuna","Mexico"},
            {"Henry Martin","Mexico"}, {"Rogelio Funes Mori","Mexico"}, {"Alexis Vega","Mexico"}, {"Roberto Alvarado","Mexico"},
            // GRUPO C - ARGENTINA
            {"Emiliano Martinez","Argentina"}, {"Franco Armani","Argentina"}, {"Geronimo Rulli","Argentina"},
            {"Nahuel Molina","Argentina"}, {"Gonzalo Montiel","Argentina"}, {"Cristian Romero","Argentina"}, {"German Pezzella","Argentina"},
            {"Nicolas Otamendi","Argentina"}, {"Lisandro Martinez","Argentina"}, {"Marcos Acuna","Argentina"}, {"Nicolas Tagliafico","Argentina"},
            {"Juan Foyth","Argentina"}, {"Rodrigo De Paul","Argentina"}, {"Leandro Paredes","Argentina"}, {"Alexis Mac Allister","Argentina"},
            {"Guido Rodriguez","Argentina"}, {"Alejandro Gomez","Argentina"}, {"Enzo Fernandez","Argentina"}, {"Exequiel Palacios","Argentina"},
            {"Lionel Messi","Argentina"}, {"Lautaro Martinez","Argentina"}, {"Angel Di Maria","Argentina"}, {"Julian Alvarez","Argentina"},
            {"Paulo Dybala","Argentina"}, {"Thiago Almada","Argentina"}, {"Angel Correa","Argentina"},
            // GRUPO C - POLONIA
            {"Wojciech Szczesny","Polonia"}, {"Lukasz Skorupski","Polonia"}, {"Kamil Grabara","Polonia"},
            {"Jan Bednarek","Polonia"}, {"Bartosz Bereszynski","Polonia"}, {"Matty Cash","Polonia"}, {"Kamil Glik","Polonia"},
            {"Robert Gumny","Polonia"}, {"Artur Jedrzejczyk","Polonia"}, {"Jakub Kiwior","Polonia"}, {"Mateusz Wieteska","Polonia"},
            {"Nicola Zalewski","Polonia"}, {"Krystian Bielik","Polonia"}, {"Przemyslaw Frankowski","Polonia"}, {"Kamil Grosicki","Polonia"},
            {"Jakub Kaminski","Polonia"}, {"Grzegorz Krychowiak","Polonia"}, {"Michal Skoras","Polonia"}, {"Damian Szymanski","Polonia"},
            {"Sebastian Szymanski","Polonia"}, {"Piotr Zielinski","Polonia"}, {"Szymon Zurkowski","Polonia"}, {"Robert Lewandowski","Polonia"},
            {"Arkadiusz Milik","Polonia"}, {"Krzysztof Piatek","Polonia"}, {"Karol Swiderski","Polonia"},
            // GRUPO D - AUSTRALIA
            {"Mat Ryan","Australia"}, {"Andrew Redmayne","Australia"}, {"Danny Vukovic","Australia"},
            {"Aziz Behich","Australia"}, {"Milos Degenek","Australia"}, {"Bailey Wright","Australia"}, {"Harry Souttar","Australia"},
            {"Fran Karacic","Australia"}, {"Nathaniel Atkinson","Australia"}, {"Joel King","Australia"}, {"Kye Rowles","Australia"},
            {"Thomas Deng","Australia"}, {"Aaron Mooy","Australia"}, {"Jackson Irvine","Australia"}, {"Ajdin Hrustic","Australia"},
            {"Riley McGree","Australia"}, {"Cameron Devlin","Australia"}, {"Keanu Baccus","Australia"}, {"Mathew Leckie","Australia"},
            {"Awer Mabil","Australia"}, {"Jamie Maclaren","Australia"}, {"Mitchell Duke","Australia"}, {"Martin Boyle","Australia"},
            {"Craig Goodwin","Australia"}, {"Garang Kuol","Australia"}, {"Jason Cummings","Australia"},
            // GRUPO D - DINAMARCA
            {"Kasper Schmeichel","Dinamarca"}, {"Oliver Christensen","Dinamarca"}, {"Frederik Ronnow","Dinamarca"},
            {"Simon Kjaer","Dinamarca"}, {"Andreas Christensen","Dinamarca"}, {"Joachim Andersen","Dinamarca"}, {"Victor Nelson","Dinamarca"},
            {"Joakim Maehle","Dinamarca"}, {"Jens Stryger Larsen","Dinamarca"}, {"Rasmus Nissen Kristensen","Dinamarca"}, {"Daniel Wass","Dinamarca"},
            {"Alexander Bah","Dinamarca"}, {"Christian Eriksen","Dinamarca"}, {"Pierre-Emile Hojbjerg","Dinamarca"}, {"Thomas Delaney","Dinamarca"},
            {"Mathias Jensen","Dinamarca"}, {"Robert Skov","Dinamarca"}, {"Christian Norgaard","Dinamarca"}, {"Andreas Skov Olsen","Dinamarca"},
            {"Martin Braithwaite","Dinamarca"}, {"Jesper Lindstrom","Dinamarca"}, {"Mikkel Damsgaard","Dinamarca"}, {"Andreas Cornelius","Dinamarca"},
            {"Kasper Dolberg","Dinamarca"}, {"Jonas Wind","Dinamarca"}, {"Yousuf Poulsen","Dinamarca"},
            // GRUPO D - FRANCA
            {"Hugo Lloris","Franca"}, {"Alphonse Areola","Franca"}, {"Steve Mandanda","Franca"},
            {"Benjamin Pavard","Franca"}, {"Ibrahima Konate","Franca"}, {"Jules Kounde","Franca"}, {"Raphael Varane","Franca"},
            {"Axel Disasi","Franca"}, {"William Saliba","Franca"}, {"Lucas Hernandez","Franca"}, {"Theo Hernandez","Franca"}, {"Dayot Upamecano","Franca"},
            {"Eduardo Camavinga","Franca"}, {"Adrien Rabiot","Franca"}, {"Aurelien Tchouameni","Franca"}, {"Youssouf Fofana","Franca"},
            {"Matteo Guendouzi","Franca"}, {"Jordan Veretout","Franca"}, {"Kingsley Coman","Franca"}, {"Kylian Mbappe","Franca"},
            {"Karim Benzema","Franca"}, {"Olivier Giroud","Franca"}, {"Antoine Griezmann","Franca"}, {"Ousmane Dembele","Franca"},
            {"Marcus Thuram","Franca"}, {"Randal Kolo Muani","Franca"},
            // GRUPO D - TUNISIA
            {"Aymen Dahmen","Tunisia"}, {"Mouez Hassen","Tunisia"}, {"Aymen Balbouli","Tunisia"}, {"Bechir Ben Said","Tunisia"},
            {"Mohamed Drager","Tunisia"}, {"Wajdi Kechrida","Tunisia"}, {"Bilel Ifa","Tunisia"}, {"Montassar Talbi","Tunisia"},
            {"Dylan Bronn","Tunisia"}, {"Yassine Meriah","Tunisia"}, {"Nader Ghandri","Tunisia"}, {"Ali Maaloul","Tunisia"},
            {"Ali Abdi","Tunisia"}, {"Ellyes Skhiri","Tunisia"}, {"Aissa Laidouni","Tunisia"}, {"Ferjani Sassi","Tunisia"},
            {"Ghailene Chaalali","Tunisia"}, {"Mohamed Ali Ben Romdhane","Tunisia"}, {"Hannibal Mejbri","Tunisia"},
            {"Seifeddine Jaziri","Tunisia"}, {"Naim Sliti","Tunisia"}, {"Taha Yassine Khenissi","Tunisia"}, {"Anis Ben Slimane","Tunisia"},
            {"Issam Jebali","Tunisia"}, {"Wahbi Khazri","Tunisia"}, {"Youssef Msakni","Tunisia"},
            // GRUPO E - ALEMANHA
            {"Manuel Neuer","Alemanha"}, {"Marc-Andre ter Stegen","Alemanha"}, {"Kevin Trapp","Alemanha"},
            {"Bella Kotchap","Alemanha"}, {"Matthias Ginter","Alemanha"}, {"Christian Gunter","Alemanha"}, {"Thilo Kehrer","Alemanha"},
            {"Lukas Klostermann","Alemanha"}, {"David Raum","Alemanha"}, {"Antonio Rudiger","Alemanha"}, {"Nico Schlotterbeck","Alemanha"},
            {"Niklas Sule","Alemanha"}, {"Karim Adeyemi","Alemanha"}, {"Julian Brandt","Alemanha"}, {"Niclas Fullkrug","Alemanha"},
            {"Serge Gnabry","Alemanha"}, {"Leon Goretzka","Alemanha"}, {"Mario Gotze","Alemanha"}, {"Ilkay Gundogan","Alemanha"},
            {"Kai Havertz","Alemanha"}, {"Jonas Hofmann","Alemanha"}, {"Joshua Kimmich","Alemanha"}, {"Youssoufa Moukoko","Alemanha"},
            {"Thomas Muller","Alemanha"}, {"Jamal Musiala","Alemanha"}, {"Leroy Sane","Alemanha"},
            // GRUPO E - COSTA RICA
            {"Keylor Navas","Costa Rica"}, {"Esteban Alvarado","Costa Rica"}, {"Patrick Sequeira","Costa Rica"},
            {"Francisco Calvo","Costa Rica"}, {"Juan Pablo Vargas","Costa Rica"}, {"Kendall Waston","Costa Rica"}, {"Oscar Duarte","Costa Rica"},
            {"Keysher Fuller","Costa Rica"}, {"Carlos Martinez","Costa Rica"}, {"Bryan Oviedo","Costa Rica"}, {"Ronald Matarrita","Costa Rica"},
            {"Yeltsin Tejeda","Costa Rica"}, {"Celso Borges","Costa Rica"}, {"Youstin Salas","Costa Rica"}, {"Roan Wilson","Costa Rica"},
            {"Gerson Torres","Costa Rica"}, {"Douglas Lopez","Costa Rica"}, {"Jewison Bennette","Costa Rica"}, {"Alvaro Zamora","Costa Rica"},
            {"Anthony Hernandez","Costa Rica"}, {"Brandon Aguilera","Costa Rica"}, {"Bryan Ruiz","Costa Rica"},
            {"Joel Campbell","Costa Rica"}, {"Anthony Contreras","Costa Rica"}, {"Johan Venegas","Costa Rica"},
            // GRUPO E - ESPANHA
            {"Unai Simon","Espanha"}, {"Robert Sanchez","Espanha"}, {"David Raya","Espanha"},
            {"Dani Carvajal","Espanha"}, {"Cesar Azpilicueta","Espanha"}, {"Eric Garcia","Espanha"}, {"Hugo Guillamon","Espanha"},
            {"Aymeric Laporte","Espanha"}, {"Pau Torres","Espanha"}, {"Jordi Alba","Espanha"}, {"Jose Gaya","Espanha"},
            {"Sergio Busquets","Espanha"}, {"Rodrigo","Espanha"}, {"Pedri","Espanha"}, {"Gavi","Espanha"}, {"Koke","Espanha"},
            {"Marcos Llorente","Espanha"}, {"Carlos Soler","Espanha"}, {"Alvaro Morata","Espanha"}, {"Ferran Torres","Espanha"},
            {"Dani Olmo","Espanha"}, {"Nico Williams","Espanha"}, {"Pablo Sarabia","Espanha"}, {"Marco Asensio","Espanha"},
            {"Yeremy Pino","Espanha"}, {"Ansu Fati","Espanha"},
            // GRUPO E - JAPAO
            {"Shuichi Gonda","Japao"}, {"Eiji Kawashima","Japao"}, {"Daniel Schmidt","Japao"},
            {"Yuto Nagatomo","Japao"}, {"Maya Yoshida","Japao"}, {"Takehiro Tomiyasu","Japao"}, {"Hiroki Sakai","Japao"},
            {"Yuta Nakayama","Japao"}, {"Shogo Taniguchi","Japao"}, {"Ko Itakura","Japao"}, {"Miki Yamane","Japao"}, {"Hiroki Ito","Japao"},
            {"Wataru Endo","Japao"}, {"Hidemasa Morita","Japao"}, {"Ao Tanaka","Japao"}, {"Daichi Kamada","Japao"},
            {"Junya Ito","Japao"}, {"Kaoru Mitoma","Japao"}, {"Takumi Minamino","Japao"}, {"Yuki Soma","Japao"}, {"Gaku Shibasaki","Japao"},
            {"Takefusa Kubo","Japao"}, {"Ritsu Doan","Japao"}, {"Daizen Maeda","Japao"}, {"Takuma Asano","Japao"}, {"Ayase Ueda","Japao"},
            // GRUPO F - BELGICA
            {"Koen Casteels","Belgica"}, {"Thibaut Courtois","Belgica"}, {"Simon Mignolet","Belgica"},
            {"Toby Alderweireld","Belgica"}, {"Zeno Debast","Belgica"}, {"Wout Faes","Belgica"}, {"Arthur Theate","Belgica"},
            {"Jan Vertonghen","Belgica"}, {"Timothy Castagne","Belgica"}, {"Thomas Meunier","Belgica"},
            {"Yannick Carrasco","Belgica"}, {"Thorgan Hazard","Belgica"}, {"Kevin De Bruyne","Belgica"}, {"Leander Dendoncker","Belgica"},
            {"Amadou Onana","Belgica"}, {"Youri Tielemans","Belgica"}, {"Axel Witsel","Belgica"}, {"Hans Vanaken","Belgica"},
            {"Charles De Ketelaere","Belgica"}, {"Jeremy Doku","Belgica"}, {"Eden Hazard","Belgica"},
            {"Leandro Trossard","Belgica"}, {"Dries Mertens","Belgica"}, {"Lois Openda","Belgica"}, {"Michy Batshuayi","Belgica"}, {"Romelu Lukaku","Belgica"},
            // GRUPO F - CANADA
            {"James Pantemis","Canada"}, {"Milan Borjan","Canada"}, {"Dayne St. Clair","Canada"},
            {"Samuel Adekugbe","Canada"}, {"Joel Waterman","Canada"}, {"Alistair Johnson","Canada"}, {"Richie Laryea","Canada"},
            {"Kamal Miller","Canada"}, {"Steven Vitoria","Canada"}, {"Derek Cornelius","Canada"},
            {"Liam Fraser","Canada"}, {"Ismael Kone","Canada"}, {"Mark-Anthony Kaye","Canada"}, {"David Wotherspoon","Canada"},
            {"Jonathan Osorio","Canada"}, {"Atiba Hutchinson","Canada"}, {"Stephen Eustaquio","Canada"}, {"Samuel Piette","Canada"},
            {"Tajon Buchanan","Canada"}, {"Liam Millar","Canada"}, {"Lucas Cavallini","Canada"}, {"Ike Ugbo","Canada"},
            {"Junior Hoilett","Canada"}, {"Jonathan David","Canada"}, {"Cyle Larin","Canada"}, {"Alphonso Davies","Canada"},
            // GRUPO F - MARROCOS
            {"Yassine Bono","Marrocos"}, {"Munir","Marrocos"}, {"Tagnaouti","Marrocos"},
            {"Achraf Hakimi","Marrocos"}, {"Noussair Mazraoui","Marrocos"}, {"Romain Saiss","Marrocos"}, {"Nayef Aguerd","Marrocos"},
            {"Achraf Dari","Marrocos"}, {"Jawad El-Yamiq","Marrocos"}, {"Yamia Attiat-Allal","Marrocos"}, {"Badr Benoun","Marrocos"},
            {"Sofyan Amrabat","Marrocos"}, {"Selim Amallah","Marrocos"}, {"Abdelhamid Sabiri","Marrocos"}, {"Azzedine Ounahi","Marrocos"},
            {"Bilel El Khannouss","Marrocos"}, {"Yahya Jabrane","Marrocos"}, {"Hakim Ziyech","Marrocos"}, {"Youssef En-Nesyri","Marrocos"},
            {"Sofiane Boufal","Marrocos"}, {"Aboukhlal","Marrocos"}, {"Ez Abde","Marrocos"}, {"Amine Harit","Marrocos"},
            {"Ilias Chair","Marrocos"}, {"Abderazak Hamdallah","Marrocos"}, {"Walid Cheddira","Marrocos"},
            // GRUPO F - CROACIA
            {"Dominik Livakovic","Croacia"}, {"Marko Ivusic","Croacia"}, {"Ivan Grbic","Croacia"},
            {"Domagoj Vida","Croacia"}, {"Dejan Lovren","Croacia"}, {"Borna Barisic","Croacia"}, {"Josip Juranovic","Croacia"},
            {"Josko Gvardiol","Croacia"}, {"Erik Sosa","Croacia"}, {"Nikola Stanicic","Croacia"}, {"Borna Sosa","Croacia"},
            {"Mario Pasalic","Croacia"}, {"Luka Modric","Croacia"}, {"Mateo Kovacic","Croacia"}, {"Marcelo Brozovic","Croacia"},
            {"Mario Pasalic (meio)","Croacia"}, {"Lovro Majer","Croacia"}, {"Kristijan Jakic","Croacia"}, {"Toni Sunjic","Croacia"},
            {"Ivan Perisic","Croacia"}, {"Andrej Kramaric","Croacia"}, {"Bruno Petkovic","Croacia"}, {"Mislav Orsic","Croacia"},
            {"Ante Budimir","Croacia"}, {"Marko Livaja","Croacia"},
            // GRUPO G - BRASIL
            {"Alisson Becker","Brasil"}, {"Ederson","Brasil"}, {"Weverton","Brasil"},
            {"Danilo","Brasil"}, {"Alex Sandro","Brasil"}, {"Dani Alves","Brasil"}, {"Alex Telles","Brasil"},
            {"Eder Militao","Brasil"}, {"Marquinhos","Brasil"}, {"Thiago Silva","Brasil"}, {"Bremer","Brasil"},
            {"Bruno Guimaraes","Brasil"}, {"Casemiro","Brasil"}, {"Fabinho","Brasil"}, {"Fred","Brasil"}, {"Lucas Paqueta","Brasil"},
            {"Everton Ribeiro","Brasil"}, {"Neymar Jr","Brasil"}, {"Vinicius Junior","Brasil"}, {"Antony","Brasil"}, {"Rodrygo","Brasil"},
            {"Raphinha","Brasil"}, {"Richarlison","Brasil"}, {"Pedro","Brasil"}, {"Gabriel Jesus","Brasil"}, {"Gabriel Martinelli","Brasil"},
            // GRUPO G - CAMAROES
            {"Andre Onana","Camaroes"}, {"Epassy","Camaroes"}, {"Ngapandouetnbu","Camaroes"},
            {"Nicolas Nkoulou","Camaroes"}, {"Ebosse","Camaroes"}, {"Jamal Tolo","Camaroes"}, {"Caleb Mbaizo","Camaroes"},
            {"Fai","Camaroes"}, {"Castelletto","Camaroes"}, {"Wooh","Camaroes"}, {"Onguene","Camaroes"},
            {"Onana (meio)","Camaroes"}, {"Gouet","Camaroes"}, {"Andre-Frank Zambo Anguissa","Camaroes"}, {"Ntcham","Camaroes"},
            {"Kudus","Camaroes"}, {"Nketiah","Camaroes"}, {"Karl Toko Ekambi","Camaroes"}, {"Aboubakar","Camaroes"},
            {"Bryan Mbeumo","Camaroes"}, {"Nsame","Camaroes"}, {"Choupo-Moting","Camaroes"}, {"Christian Bassogog","Camaroes"}, {"Marou","Camaroes"},
            // GRUPO G - SERVIA
            {"Marko Dmitrovic","Servia"}, {"Predrag Rajkovic","Servia"}, {"Vanja Milinkovic-Savic","Servia"},
            {"Stefan Mitrovic","Servia"}, {"Nikola Milenkovic","Servia"}, {"Strahinja Pavlovic","Servia"}, {"Milos Veljkovic","Servia"},
            {"Filip Mladenovic","Servia"}, {"Strahinja Erakovic","Servia"}, {"Srdan Babic","Servia"},
            {"Nemanja Gudelj","Servia"}, {"Sergej Milinkovic-Savic","Servia"}, {"Sasa Lukic","Servia"}, {"Marko Grujic","Servia"},
            {"Filip Kostic","Servia"}, {"Uros Racic","Servia"}, {"Nemanja Maksimovic","Servia"}, {"Ivan Ilic","Servia"},
            {"Andrija Zivkovic","Servia"}, {"Darko Lazic","Servia"}, {"Dusan Tadic","Servia"}, {"Aleksandar Mitrovic","Servia"},
            {"Dusan Vlahovic","Servia"}, {"Filip Djuricic","Servia"}, {"Luka Jovic","Servia"}, {"Nemanja Radonjic","Servia"},
            // GRUPO G - SUICA
            {"Gregor Kobel","Suica"}, {"Diogo Kohn","Suica"}, {"Yann Sommer","Suica"}, {"Manuel Akanji","Suica"},
            {"Eray Comert","Suica"}, {"Nico Elvedi","Suica"}, {"Pablo Mari Fernandes","Suica"}, {"Ricardo Rodriguez","Suica"},
            {"Fabian Schar","Suica"}, {"Silvan Widmer","Suica"}, {"Michel Aebischer","Suica"}, {"Breel Embolo","Suica"},
            {"Renato Steffen","Suica"}, {"Jerome Omlin","Suica"}, {"Haris Seferovic","Suica"}, {"Xherdan Shaqiri","Suica"},
            {"Edimilson Fernandes","Suica"}, {"Steven Zuber","Suica"}, {"Denis Zakaria","Suica"},
            // GRUPO H - GANA
            {"Ibrahim Danlad","Gana"}, {"Abdul Manaf Nurudeen","Gana"}, {"Lawrence Ati-Zigi","Gana"},
            {"Daniel Amartey","Gana"}, {"Mohammed Salisu","Gana"}, {"Alexander Djiku","Gana"}, {"Alidu Seidu","Gana"},
            {"Tariq Lamptey","Gana"}, {"Abdul Rahman Baba","Gana"}, {"Gideon Mensah","Gana"}, {"Denis Odoi","Gana"}, {"Joseph Aidoo","Gana"},
            {"Salis Abdul Samed","Gana"}, {"Thomas Partey","Gana"}, {"Elisha Owusu","Gana"}, {"Daniel Afriyie Barnieh","Gana"},
            {"Kamal Sowah","Gana"}, {"Mohammed Kudus","Gana"}, {"Andre Ayew","Gana"}, {"Daniel-Kofi Kyereh","Gana"},
            {"Osman Bukari","Gana"}, {"Jordan Ayew","Gana"}, {"Inaki Williams","Gana"}, {"Abdul Fatawu Issahaku","Gana"},
            {"Kamaldeen Sulemana","Gana"}, {"Antoine Semenyo","Gana"},
            // GRUPO H - COREIA DO SUL
            {"Kim Seung-gyu","Coreia do Sul"}, {"Jo Hyeon-woo","Coreia do Sul"}, {"Song Bum-keun","Coreia do Sul"},
            {"Kim Min-jae","Coreia do Sul"}, {"Kim Jin-su","Coreia do Sul"}, {"Hong Chul","Coreia do Sul"}, {"Kim Moon-hwan","Coreia do Sul"},
            {"Yoon Jong-gyu","Coreia do Sul"}, {"Kim Young-gwon","Coreia do Sul"}, {"Kim Tae-hwan","Coreia do Sul"}, {"Kwon Kyung-won","Coreia do Sul"},
            {"Cho Yu-min","Coreia do Sul"}, {"Jung Woo-young","Coreia do Sul"}, {"Na Sang-ho","Coreia do Sul"}, {"Paik Seung-ho","Coreia do Sul"},
            {"Son Jun-ho","Coreia do Sul"}, {"Song Min-kyu","Coreia do Sul"}, {"Kwon Chang-hoon","Coreia do Sul"}, {"Lee Jae-sung","Coreia do Sul"},
            {"Hwang Hee-chan","Coreia do Sul"}, {"Hwang In-beom","Coreia do Sul"}, {"Jeong Woo-yeong","Coreia do Sul"}, {"Lee Kang-in","Coreia do Sul"},
            {"Hwang Ui-jo","Coreia do Sul"}, {"Cho Gue-sung","Coreia do Sul"}, {"Son Heung-min","Coreia do Sul"},
            // GRUPO H - PORTUGAL
            {"Diogo Costa","Portugal"}, {"Jose Sa","Portugal"}, {"Rui Patricio","Portugal"},
            {"Diogo Dalot","Portugal"}, {"Joao Cancelo","Portugal"}, {"Antonio Silva","Portugal"}, {"Danilo Pereira","Portugal"},
            {"Pepe","Portugal"}, {"Ruben Dias","Portugal"}, {"Nuno Mendes","Portugal"}, {"Raphael Guerreiro","Portugal"},
            {"Joao Palhinha","Portugal"}, {"Ruben Neves","Portugal"}, {"Bernardo Silva","Portugal"}, {"Bruno Fernandes","Portugal"},
            {"Joao Mario","Portugal"}, {"Matheus Nunes","Portugal"}, {"Otavio","Portugal"}, {"Vitinha","Portugal"}, {"William Carvalho","Portugal"},
            {"Andre Silva","Portugal"}, {"Cristiano Ronaldo","Portugal"}, {"Goncalo Ramos","Portugal"}, {"Joao Felix","Portugal"},
            {"Rafael Leao","Portugal"}, {"Ricardo Horta","Portugal"},
            // GRUPO H - URUGUAI
            {"Sergio Rochet","Uruguai"}, {"Fernando Muslera","Uruguai"}, {"Sebastian Sosa","Uruguai"},
            {"Ronald Araujo","Uruguai"}, {"Jose Luis Rodriguez","Uruguai"}, {"Guillermo Varela","Uruguai"}, {"Jose Maria Gimenez","Uruguai"},
            {"Sebastian Coates","Uruguai"}, {"Diego Godin","Uruguai"}, {"Martin Caceres","Uruguai"}, {"Matias Vina","Uruguai"},
            {"Mathias Olivera","Uruguai"}, {"Matias Vecino","Uruguai"}, {"Rodrigo Bentancur","Uruguai"}, {"Federico Valverde","Uruguai"},
            {"Lucas Torreira","Uruguai"}, {"Manuel Ugarte","Uruguai"}, {"Facundo Pellistri","Uruguai"}, {"Nicolas De la Cruz","Uruguai"},
            {"Giorgian de Arrascaeta","Uruguai"}, {"Facundo Torres","Uruguai"}, {"Darwin Nunez","Uruguai"}, {"Luis Suarez","Uruguai"},
            {"Edinson Cavani","Uruguai"}, {"Maximiliano Gomez","Uruguai"}, {"Agustin Canobbio","Uruguai"}
        };

        std::ofstream out("figurinhas.csv");
        int id = 1;
        for (auto &p : inic) {
            catalogo.emplace_back(id, p.first, p.second);
            out << id << ";" << p.first << ";" << p.second << "\n";
            id++;
        }
        out.close();
        return;
    }

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string f1,f2,f3;
        if (!std::getline(iss,f1,';')) continue;
        if (!std::getline(iss,f2,';')) continue;
        if (!std::getline(iss,f3,';')) f3="";
        int id = std::stoi(f1);
        catalogo.emplace_back(id,f2,f3);
    }
    in.close();
}

void Album::carregarUsuarios() {
    usuarios.clear();
    std::ifstream in("usuarios.csv");
    if (!in.is_open()) return;
    std::string line;
    while (std::getline(in,line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string user, pass, colecaoStr;
        if (!std::getline(iss, user, ';')) continue;
        if (!std::getline(iss, pass, ';')) pass="";
        if (!std::getline(iss, colecaoStr)) colecaoStr="";
        Usuario u(user, pass);
        u.carregarColecaoFromString(colecaoStr);
        usuarios.push_back(u);
    }
    in.close();
}

void Album::carregarTrocas() {
    trocas.clear();
    std::ifstream in("trocas.csv");
    if (!in.is_open()) return;
    std::string line;
    int maxId = 0;
    while (std::getline(in,line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string sId, remet, dest, sdesej, sofert, sstatus;
        if (!std::getline(iss,sId,';')) continue;
        if (!std::getline(iss,remet,';')) continue;
        if (!std::getline(iss,dest,';')) continue;
        if (!std::getline(iss,sdesej,';')) continue;
        if (!std::getline(iss,sofert,';')) continue;
        if (!std::getline(iss,sstatus)) sstatus="0";
        int id = std::stoi(sId);
        int desej = std::stoi(sdesej);
        int ofert = std::stoi(sofert);
        int status = std::stoi(sstatus);
        trocas.emplace_back(id, remet, dest, desej, ofert, status);
        if (id > maxId) maxId = id;
    }
    proximaIdTroca = maxId + 1;
    in.close();
}

void Album::salvarFigurinhas() {
    std::ofstream out("figurinhas.csv");
    for (auto &f : catalogo) {
        out << f.id << ";" << f.nome << ";" << f.selecao << "\n";
    }
    out.close();
}

void Album::salvarUsuarios() {
    std::ofstream out("usuarios.csv");
    for (auto &u : usuarios) {
        out << u.username << ";" << u.password << ";" << u.colecaoToString() << "\n";
    }
    out.close();
}

void Album::salvarTrocas() {
    std::ofstream out("trocas.csv");
    for (auto &t : trocas) {
        out << t.id << ";" << t.remetente << ";" << t.destinatario << ";" << t.figDesejada << ";" << t.figOfertada << ";" << t.status << "\n";
    }
    out.close();
}

void Album::criarUsuario() {
    std::string user, pass;
    std::cout << "Novo usuario - digite nome: ";
    std::getline(std::cin, user);
    if (user.empty()) { std::cout << "Nome vazio. Abortando.\n"; return; }
    if (buscarUsuarioPorNome(user)) { std::cout << "Usuario ja existe.\n"; return; }
    std::cout << "Digite senha: ";
    std::getline(std::cin, pass);
    Usuario u(user, pass);
    usuarios.push_back(u);
    std::cout << "Usuario criado.\n";
}

Usuario* Album::autenticar(const std::string &user, const std::string &pass) {
    for (auto &u : usuarios) {
        if (u.username == user && u.password == pass) return &u;
    }
    return nullptr;
}

void Album::menuPrincipal() {
    while (true) {
        std::cout << "\n--- Album Virtual ---\n";
        std::cout << "1 - Novo Album\n2 - Acessar Album\n3 - Sair\nEscolha: ";
        std::string op;
        std::getline(std::cin, op);
        if (op == "1") criarUsuario();
        else if (op == "2") {
            std::string user, pass;
            std::cout << "Usuario: ";
            std::getline(std::cin, user);
            std::cout << "Senha: ";
            std::getline(std::cin, pass);
            Usuario* u = autenticar(user, pass);
            if (!u) { std::cout << "Credenciais invalidas.\n"; }
            else menuUsuario(*u);
        } else if (op == "3") {
            salvarDados();
            std::cout << "Dados salvos. Saindo.\n";
            return;
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}

void Album::menuUsuario(Usuario &u) {
    while (true) {
        std::cout << "\nUsuario: " << u.username << "\n";
        std::cout << "1 - Ver Album\n2 - Gerenciar a colecao\n3 - Abrir pacote de figurinhas\n4 - Voltar\nEscolha: ";
        std::string op;
        std::getline(std::cin, op);
        if (op == "1") verAlbum(u);
        else if (op == "2") gerenciarColecao(u);
        else if (op == "3") abrirPacote(u);
        else if (op == "4") { salvarDados(); return; }
        else std::cout << "Opcao invalida.\n";
    }
}

void Album::verAlbum(Usuario &u) {
    int page = 0;
    const int porPagina = 10;
    int total = (int)catalogo.size();
    int paginas = (total + porPagina - 1) / porPagina;
    while (true) {
        int start = page * porPagina;
        int end = std::min(start + porPagina, total);
        std::cout << "\nPagina " << (page+1) << " de " << paginas << "\n";
        for (int i = start; i < end; ++i) {
            const Figurinha &f = catalogo[i];
            int st = u.status(f.id);
            std::cout << f.id << " - " << f.nome << " (" << f.selecao << ") - ";
            if (st == 1) std::cout << "COLADA\n";
            else if (st == 0) std::cout << "NA COLECAO (COLAR)\n";
            else if (st == 2) std::cout << "DISPONIVEL PARA TROCA\n";
            else std::cout << "NAO POSSUI\n";
        }
        std::cout << "n - proxima, p - anterior, v - voltar: ";
        std::string cmd;
        std::getline(std::cin, cmd);
        if (cmd == "n" && page+1 < paginas) page++;
        else if (cmd == "p" && page>0) page--;
        else if (cmd == "v") return;
        else std::cout << "Comando invalido.\n";
    }
}

void Album::gerenciarColecao(Usuario &u) {
    while (true) {
        std::cout << "\n--- Gerenciar Colecao ---\n";
        std::cout << "Figurinhas na colecao (id : status)\n";

        for (auto &p : u.colecao) {
            int id = p.first;
            int st = p.second;
            const Figurinha* f = buscarFigurinhaPorId(id);
            std::string nome = f ? f->nome : "Desconhecida";
            std::cout << id << " : " << nome << " - ";
            if (st == 0) std::cout << "NA COLECAO\n";
            else if (st == 1) std::cout << "COLADA\n";
            else if (st == 2) std::cout << "DISPONIVEL PARA TROCA\n";
        }

        std::cout << "\nOpcoes:\n";
        std::cout << "1 - Colar Figurinha\n";
        std::cout << "2 - Disponibilizar para troca\n";
        std::cout << "3 - Colar TODAS as figurinhas\n";
        std::cout << "4 - Propor troca\n";
        std::cout << "5 - Revisar solicitacoes de troca\n";
        std::cout << "6 - Voltar\n";
        std::cout << "Escolha: ";

        std::string op;
        std::getline(std::cin, op);

        if (op == "1") {
            std::cout << "Informe id da figurinha a colar: ";
            std::string s;
            std::getline(std::cin, s);
            int id = std::stoi(s);
            if (u.possui(id) && u.status(id) != 1) {
                u.colar(id);
                std::cout << "Figurinha colada.\n";
            } else {
                std::cout << "Nao pode colar essa figurinha.\n";
            }
        }

        else if (op == "2") {
            std::cout << "Informe id da figurinha a disponibilizar: ";
            std::string s;
            std::getline(std::cin, s);
            int id = std::stoi(s);
            if (u.possui(id) && u.status(id) != 1) {
                u.disponibilizarParaTroca(id);
                std::cout << "Figurinha disponivel para troca.\n";
            } else {
                std::cout << "Nao pode disponibilizar essa figurinha.\n";
            }
        }

        else if (op == "3") {
            int contador = 0;
            for (auto &p : u.colecao) {
                if (p.second != 1) {
                    p.second = 1;
                    contador++;
                }
            }
            std::cout << contador << " figurinhas coladas automaticamente.\n";
        }

        else if (op == "4") {
            proporTroca(u);
        }

        else if (op == "5") {
            revisarTrocas(u);
        }

        else if (op == "6") {
            return;
        }

        else {
            std::cout << "Opcao invalida.\n";
        }
    }
}


void Album::abrirPacote(Usuario &u) {
    std::cout << "Abrindo pacote... voce recebera 3 figurinhas.\n";
    int n = (int)catalogo.size();
    for (int k = 0; k < 3; ++k) {
        int id = 1 + (std::rand() % n);
        if (!u.possui(id)) {
            u.adicionar(id, 0);
            const Figurinha* f = buscarFigurinhaPorId(id);
            std::cout << "Recebeu: " << id << " - " << (f?f->nome:"Desconhecida") << " (" << (f?f->selecao:"") << ")\n";
        } else {
            const Figurinha* f = buscarFigurinhaPorId(id);
            std::cout << "Ja possuia: " << id << " - " << (f?f->nome:"Desconhecida") << "\n";
        }
    }
    std::cout << "Pacote aberto. Voltando ao menu.\n";
}

void Album::listarUsuariosComFigurasDisponiveis(const Usuario &u) {
    for (auto &other : usuarios) {
        if (other.username == u.username) continue;
        bool tem = false;
        for (auto &p : other.colecao) if (p.second == 2) { tem = true; break; }
        if (tem) {
            std::cout << "Usuario: " << other.username << " - figurinhas disponiveis:\n";
            for (auto &p : other.colecao) {
                if (p.second == 2) {
                    const Figurinha* f = buscarFigurinhaPorId(p.first);
                    std::cout << "  " << p.first << " - " << (f?f->nome:"Desconhecida") << "\n";
                }
            }
        }
    }
}

Usuario* Album::buscarUsuarioPorNome(const std::string &nome) {
    for (auto &u : usuarios) if (u.username == nome) return &u;
    return nullptr;
}

void Album::proporTroca(Usuario &u) {
    listarUsuariosComFigurasDisponiveis(u);
    std::cout << "Escolha usuario para propor troca (digite nome) ou vazio para cancelar: ";
    std::string parceiro; std::getline(std::cin, parceiro);
    if (parceiro.empty()) return;
    Usuario* p = buscarUsuarioPorNome(parceiro);
    if (!p) { std::cout << "Parceiro nao encontrado.\n"; return; }
    std::cout << "Informe id da figurinha que deseja (do parceiro): ";
    std::string s1; std::getline(std::cin, s1);
    int deseja = std::stoi(s1);
    if (!p->possui(deseja) || p->status(deseja) != 2) { std::cout << "Parceiro nao tem essa figurinha disponivel.\n"; return; }
    std::cout << "Informe id da sua figurinha que oferece: ";
    std::string s2; std::getline(std::cin, s2);
    int oferta = std::stoi(s2);
    if (!u.possui(oferta) || u.status(oferta) == 1) { std::cout << "Voce nao tem essa figurinha disponivel para oferta.\n"; return; }
    int idT = gerarIdTroca();
    trocas.emplace_back(idT, u.username, p->username, deseja, oferta, 0);
    std::cout << "Proposta enviada. ID da troca: " << idT << "\n";
}

void Album::revisarTrocas(Usuario &u) {
    std::vector<int> indices;
    for (size_t i=0;i<trocas.size();++i) {
        if (trocas[i].destinatario == u.username && trocas[i].status == 0) indices.push_back((int)i);
    }
    if (indices.empty()) { std::cout << "Nenhuma solicitacao para revisar.\n"; return; }
    std::cout << "Solicitacoes pendentes:\n";
    for (size_t k=0;k<indices.size();++k) {
        Troca &t = trocas[indices[k]];
        std::cout << k << " - ID:" << t.id << " remetente:" << t.remetente << " pede:" << t.figDesejada << " oferece:" << t.figOfertada << "\n";
    }
    std::cout << "Escolha index da solicitacao para revisar ou vazio para sair: ";
    std::string s; std::getline(std::cin, s);
    if (s.empty()) return;
    int idx = std::stoi(s);
    if (idx < 0 || idx >= (int)indices.size()) { std::cout << "Index invalido.\n"; return; }
    Troca &t = trocas[indices[idx]];
    std::cout << "Aceitar (a) / Recusar (r)?: ";
    std::string resp; std::getline(std::cin, resp);
    if (resp == "r") {
        t.status = 2;
        std::cout << "Recusada.\n";
        return;
    } else if (resp == "a") {
        Usuario* remet = buscarUsuarioPorNome(t.remetente);
        Usuario* dest = buscarUsuarioPorNome(t.destinatario);
        if (!remet || !dest) { std::cout << "Usuario envolvido nao encontrado.\n"; t.status = 2; return; }
        if (!remet->possui(t.figOfertada) || remet->status(t.figOfertada) == 1) { std::cout << "Remetente nao tem oferta valida. Cancelando.\n"; t.status = 2; return; }
        if (!dest->possui(t.figDesejada) || dest->status(t.figDesejada) == 1) { std::cout << "Voce nao tem a figurinha desejada colada ou indisponivel. Cancelando.\n"; t.status = 2; return; }
        dest->remover(t.figDesejada);
        remet->remover(t.figOfertada);
        remet->adicionar(t.figDesejada, 0);
        dest->adicionar(t.figOfertada, 0);
        t.status = 1;
        std::cout << "Troca aceita e aplicada.\n";
        return;
    } else {
        std::cout << "Comando invalido.\n";
    }
}

int Album::gerarIdTroca() {
    return proximaIdTroca++;
}

const Figurinha* Album::buscarFigurinhaPorId(int id) const {
    for (const auto &f : catalogo) if (f.id == id) return &f;
    return nullptr;
}