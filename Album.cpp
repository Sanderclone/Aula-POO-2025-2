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
        // Cria figurinhas.csv com todo o catálogo completo (Copa 2022) a partir da lista fornecida.
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
            {"Alexander Domínguez","Equador"}, {"Hernán Galíndez","Equador"}, {"Moisés Ramírez","Equador"},
            {"Piero Hincapié","Equador"}, {"Félix Torres","Equador"}, {"Robert Arboleda","Equador"}, {"Xavier Arreaga","Equador"},
            {"Jackson Porozo","Equador"}, {"Angelo Preciado","Equador"}, {"Pervis Estupiñán","Equador"}, {"William Pacho","Equador"},
            {"Diego Palacios","Equador"}, {"Moisés Caicedo","Equador"}, {"Carlos Gruezo","Equador"}, {"Jhegson Méndez","Equador"},
            {"Alan Franco","Equador"}, {"José Cifuentes","Equador"}, {"Ángel Mena","Equador"}, {"Gonzalo Plata","Equador"},
            {"Jeremy Sarmiento","Equador"}, {"Romario Ibarra","Equador"}, {"Ayrton Preciado","Equador"},
            {"Énner Valencia","Equador"}, {"Michael Estrada","Equador"}, {"Djorkaeff Reasco","Equador"}, {"Kevin Rodríguez","Equador"},
            // GRUPO A - HOLANDA
            {"Justin Bijlow","Holanda"}, {"Andries Noppert","Holanda"}, {"Remko Pasveer","Holanda"},
            {"Virgil van Dijk","Holanda"}, {"Nathan Aké","Holanda"}, {"Daley Blind","Holanda"}, {"Jurrien Timber","Holanda"},
            {"Denzel Dumfries","Holanda"}, {"Stefan De Vrij","Holanda"}, {"Matthijs De Ligt","Holanda"}, {"Tyrell Malacia","Holanda"},
            {"Jeremie Frimpong","Holanda"}, {"Frenkie De Jong","Holanda"}, {"Steven Berghuis","Holanda"}, {"Davy Klassen","Holanda"},
            {"Teun Koopmeiners","Holanda"}, {"Cody Gakpo","Holanda"}, {"Marten De Roon","Holanda"}, {"Kenneth Taylor","Holanda"},
            {"Xavi Simons","Holanda"}, {"Memphis Depay","Holanda"}, {"Steven Bergwijn","Holanda"}, {"Vincent Janssen","Holanda"},
            {"Luuk De Jong","Holanda"}, {"Noa Lang","Holanda"}, {"Wout Weghorst","Holanda"},
            // GRUPO A - SENEGAL
            {"Seny Dieng","Senegal"}, {"Alfred Gomis","Senegal"}, {"Edouard Mendy","Senegal"},
            {"Pape Abou Cissé","Senegal"}, {"Abdou Diallo","Senegal"}, {"Ismail Jakobs","Senegal"}, {"Kalidou Koulibaly","Senegal"},
            {"Formose Mendy","Senegal"}, {"Youssouf Sabaly","Senegal"}, {"Fodé Ballo Touré","Senegal"},
            {"Pathé Ciss","Senegal"}, {"Krépin Diatta","Senegal"}, {"Gana Gueye","Senegal"}, {"Pape Gueye","Senegal"},
            {"Cheikhou Kouyaté","Senegal"}, {"Mamadou Loum","Senegal"}, {"Nampalys Mendy","Senegal"}, {"Moustapha Name","Senegal"},
            {"Papa Matar Sarr","Senegal"}, {"Boulaye Dia","Senegal"}, {"Bamba Dieng","Senegal"}, {"Nicolas Jackson","Senegal"},
            {"Sadio Mané","Senegal"}, {"Iliman Ndiaye","Senegal"}, {"Ismaila Sarr","Senegal"}, {"Famara Diedhiou","Senegal"},
            // GRUPO B - IRÃ
            {"Alireza Beiranvand","Irã"}, {"Amir Abedzadeh","Irã"}, {"Seyed Hossein Hosseini","Irã"}, {"Payam Niazmand","Irã"},
            {"Ehsan Hajsafi","Irã"}, {"Morteza Pouraliganji","Irã"}, {"Ramin Rezaeian","Irã"}, {"Milad Mohammadi","Irã"},
            {"Hossein Kanaanizadegan","Irã"}, {"Shojae Khalilzadeh","Irã"}, {"Sadegh Moharrami","Irã"}, {"Rouzbeh Cheshmi","Irã"},
            {"Majid Hosseini","Irã"}, {"Abolfazl Jalali","Irã"}, {"Ahmad Noorollahi","Irã"}, {"Saman Ghoddos","Irã"},
            {"Vahid Amiri","Irã"}, {"Saeid Ezatolahi","Irã"}, {"Alireza Jahanbakhsh","Irã"}, {"Mehdi Torabi","Irã"},
            {"Ali Gholizadeh","Irã"}, {"Ali Karimi","Irã"}, {"Karim Ansarifard","Irã"}, {"Sardar Azmoun","Irã"}, {"Mehdi Taremi","Irã"},
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
            // GRUPO B - PAÍS DE GALES
            {"Adam Davies","País de Gales"}, {"Wayne Hennessey","País de Gales"}, {"Danny Ward","País de Gales"},
            {"Ben Davies","País de Gales"}, {"Ben Cabango","País de Gales"}, {"Tom Lockyer","País de Gales"},
            {"Joe Rodon","País de Gales"}, {"Chris Mepham","País de Gales"}, {"Ethan Ampadu","País de Gales"},
            {"Chris Gunter","País de Gales"}, {"Neco Williams","País de Gales"}, {"Connor Roberts","País de Gales"},
            {"Sorba Thomas","País de Gales"}, {"Joe Allen","País de Gales"}, {"Matt Smith","País de Gales"}, {"Dylan Levitt","País de Gales"},
            {"Harry Wilson","País de Gales"}, {"Joe Morrell","País de Gales"}, {"Jonny Williams","País de Gales"},
            {"Aaron Ramsey","País de Gales"}, {"Rubin Colwill","País de Gales"}, {"Gareth Bale","País de Gales"},
            {"Kieffer Moore","País de Gales"}, {"Mark Harris","País de Gales"}, {"Brennan Johnson","País de Gales"}, {"Dan James","País de Gales"},
            // GRUPO C - ARÁBIA SAUDITA
            {"Muhammed Al Owais","Arábia Saudita"}, {"Mohammed Al Yammi","Arábia Saudita"}, {"Nawaf Al-Aqeedi","Arábia Saudita"},
            {"Sultan Al-Ghanam","Arábia Saudita"}, {"Mohammed Al-Buraik","Arábia Saudita"}, {"Abdulelah Al-Amri","Arábia Saudita"},
            {"Ali Al-Bulayhi","Arábia Saudita"}, {"Abdullah Mado","Arábia Saudita"}, {"Hassan Tambakti","Arábia Saudita"},
            {"Saud Abdulhamid","Arábia Saudita"}, {"Yasser Al-Shahrani","Arábia Saudita"}, {"Salman Al-Faraj","Arábia Saudita"},
            {"Salem Al-Dawsari","Arábia Saudita"}, {"Abdulellah Al-Malki","Arábia Saudita"}, {"Mohamed Kanoo","Arábia Saudita"},
            {"Abdullah Al-Aboud","Arábia Saudita"}, {"Sami Al-Najei","Arábia Saudita"}, {"Hattan Bahbri","Arábia Saudita"},
            {"Nasser Al-Dawsari","Arábia Saudita"}, {"Ali Al-Hassan","Arábia Saudita"}, {"Riad Shrahili","Arábia Saudita"},
            {"Abdullah Otayf","Arábia Saudita"}, {"Saleh Al-Shehri","Arábia Saudita"}, {"Firas Al-Braikan","Arábia Saudita"},
            {"Haitham Asiri","Arábia Saudita"}, {"Nawaf Al Abed","Arábia Saudita"},
            // GRUPO C - MÉXICO
            {"Guillermo Ochoa","México"}, {"Rodolfo Cota","México"}, {"Alfredo Talavera","México"},
            {"Jorge Sánchez","México"}, {"Kevin Álvarez","México"}, {"Néstor Araujo","México"}, {"Johan Vásquez","México"},
            {"Gerardo Arteaga","México"}, {"Héctor Moreno","México"}, {"César Montes","México"}, {"Jesús Gallardo","México"},
            {"Andrés Guardado","México"}, {"Héctor Herrera","México"}, {"Carlos Rodríguez","México"}, {"Érick Gutiérrez","México"},
            {"Luis Chávez","México"}, {"Édson Álvarez","México"}, {"Luis Romo","México"},
            {"Orbelín Pineda","México"}, {"Hirving Lozano","México"}, {"Raúl Jiménez","México"}, {"Uriel Antuna","México"},
            {"Henry Martín","México"}, {"Rogelio Funes Mori","México"}, {"Alexis Vega","México"}, {"Roberto Alvarado","México"},
            // GRUPO C - ARGENTINA
            {"Emiliano Martínez","Argentina"}, {"Franco Armani","Argentina"}, {"Gerónimo Rulli","Argentina"},
            {"Nahuel Molina","Argentina"}, {"Gonzalo Montiel","Argentina"}, {"Cristian Romero","Argentina"}, {"Germán Pezzella","Argentina"},
            {"Nicolás Otamendi","Argentina"}, {"Lisandro Martínez","Argentina"}, {"Marcos Acuña","Argentina"}, {"Nicolás Tagliafico","Argentina"},
            {"Juan Foyth","Argentina"}, {"Rodrigo De Paul","Argentina"}, {"Leandro Paredes","Argentina"}, {"Alexis Mac Allister","Argentina"},
            {"Guido Rodríguez","Argentina"}, {"Alejandro Gómez","Argentina"}, {"Enzo Fernández","Argentina"}, {"Exequiel Palacios","Argentina"},
            {"Lionel Messi","Argentina"}, {"Lautaro Martínez","Argentina"}, {"Ángel Di María","Argentina"}, {"Julián Álvarez","Argentina"},
            {"Paulo Dybala","Argentina"}, {"Thiago Almada","Argentina"}, {"Ángel Correa","Argentina"},
            // GRUPO C - POLÔNIA
            {"Wojciech Szczesny","Polônia"}, {"Lukasz Skorupski","Polônia"}, {"Kamil Grabara","Polônia"},
            {"Jan Bednarek","Polônia"}, {"Bartosz Bereszynski","Polônia"}, {"Matty Cash","Polônia"}, {"Kamil Glik","Polônia"},
            {"Robert Gumny","Polônia"}, {"Artur Jedrzejczyk","Polônia"}, {"Jakub Kiwior","Polônia"}, {"Mateusz Wieteska","Polônia"},
            {"Nicola Zalewski","Polônia"}, {"Krystian Bielik","Polônia"}, {"Przemyslaw Frankowski","Polônia"}, {"Kamil Grosicki","Polônia"},
            {"Jakub Kaminski","Polônia"}, {"Grzegorz Krychowiak","Polônia"}, {"Michal Skóras","Polônia"}, {"Damian Szymanski","Polônia"},
            {"Sebastian Szymanski","Polônia"}, {"Piotr Zielinski","Polônia"}, {"Szymon Zurkowski","Polônia"}, {"Robert Lewandowski","Polônia"},
            {"Arkadiusz Milik","Polônia"}, {"Krzysztof Piatek","Polônia"}, {"Karol Swiderski","Polônia"},
            // GRUPO D - AUSTRÁLIA
            {"Mat Ryan","Austrália"}, {"Andrew Redmayne","Austrália"}, {"Danny Vukovic","Austrália"},
            {"Aziz Behich","Austrália"}, {"Milos Degenek","Austrália"}, {"Bailey Wright","Austrália"}, {"Harry Souttar","Austrália"},
            {"Fran Karacic","Austrália"}, {"Nathaniel Atkinson","Austrália"}, {"Joel King","Austrália"}, {"Kye Rowles","Austrália"},
            {"Thomas Deng","Austrália"}, {"Aaron Mooy","Austrália"}, {"Jackson Irvine","Austrália"}, {"Ajdin Hrustic","Austrália"},
            {"Riley McGree","Austrália"}, {"Cameron Devlin","Austrália"}, {"Keanu Baccus","Austrália"}, {"Mathew Leckie","Austrália"},
            {"Awer Mabil","Austrália"}, {"Jamie Maclaren","Austrália"}, {"Mitchell Duke","Austrália"}, {"Martin Boyle","Austrália"},
            {"Craig Goodwin","Austrália"}, {"Garang Kuol","Austrália"}, {"Jason Cummings","Austrália"},
            // GRUPO D - DINAMARCA
            {"Kasper Schmeichel","Dinamarca"}, {"Oliver Christensen","Dinamarca"}, {"Frederik Ronnow","Dinamarca"},
            {"Simon Kjaer","Dinamarca"}, {"Andreas Christensen","Dinamarca"}, {"Joachim Andersen","Dinamarca"}, {"Victor Nelson","Dinamarca"},
            {"Joakim Maehle","Dinamarca"}, {"Jens Stryger Larsen","Dinamarca"}, {"Rasmus Nissen Kristensen","Dinamarca"}, {"Daniel Wass","Dinamarca"},
            {"Alexander Bah","Dinamarca"}, {"Christian Eriksen","Dinamarca"}, {"Pierre-Emile Højbjerg","Dinamarca"}, {"Thomas Delaney","Dinamarca"},
            {"Mathias Jensen","Dinamarca"}, {"Robert Skov","Dinamarca"}, {"Christian Norgaard","Dinamarca"}, {"Andreas Skov Olsen","Dinamarca"},
            {"Martin Braithwaite","Dinamarca"}, {"Jesper Lindstrom","Dinamarca"}, {"Mikkel Damsgaard","Dinamarca"}, {"Andreas Cornelius","Dinamarca"},
            {"Kasper Dolberg","Dinamarca"}, {"Jonas Wind","Dinamarca"}, {"Yousuf Poulsen","Dinamarca"},
            // GRUPO D - FRANÇA
            {"Hugo Lloris","França"}, {"Alphonse Areola","França"}, {"Steve Mandanda","França"},
            {"Benjamin Pavard","França"}, {"Ibrahima Konaté","França"}, {"Jules Koundé","França"}, {"Raphaël Varane","França"},
            {"Axel Disasi","França"}, {"William Saliba","França"}, {"Lucas Hernandez","França"}, {"Theo Hernandez","França"}, {"Dayot Upamecano","França"},
            {"Eduardo Camavinga","França"}, {"Adrien Rabiot","França"}, {"Aurélien Tchouaméni","França"}, {"Youssouf Fofana","França"},
            {"Mattéo Guendouzi","França"}, {"Jordan Veretout","França"}, {"Kingsley Coman","França"}, {"Kylian Mbappé","França"},
            {"Karim Benzema","França"}, {"Olivier Giroud","França"}, {"Antoine Griezmann","França"}, {"Ousmane Dembélé","França"},
            {"Marcus Thuram","França"}, {"Randal Kolo Muani","França"},
            // GRUPO D - TUNÍSIA
            {"Aymen Dahmen","Tunísia"}, {"Mouez Hassen","Tunísia"}, {"Aymen Balbouli","Tunísia"}, {"Bechir Ben Said","Tunísia"},
            {"Mohamed Drager","Tunísia"}, {"Wajdi Kechrida","Tunísia"}, {"Bilel Ifa","Tunísia"}, {"Montassar Talbi","Tunísia"},
            {"Dylan Bronn","Tunísia"}, {"Yassine Meriah","Tunísia"}, {"Nader Ghandri","Tunísia"}, {"Ali Maaloul","Tunísia"},
            {"Ali Abdi","Tunísia"}, {"Ellyes Skhiri","Tunísia"}, {"Aissa Laidouni","Tunísia"}, {"Ferjani Sassi","Tunísia"},
            {"Ghailene Chaalali","Tunísia"}, {"Mohamed Ali Ben Romdhane","Tunísia"}, {"Hannibal Mejbri","Tunísia"},
            {"Seifeddine Jaziri","Tunísia"}, {"Naim Sliti","Tunísia"}, {"Taha Yassine Khenissi","Tunísia"}, {"Anis Ben Slimane","Tunísia"},
            {"Issam Jebali","Tunísia"}, {"Wahbi Khazri","Tunísia"}, {"Youssef Msakni","Tunísia"},
            // GRUPO E - ALEMANHA
            {"Manuel Neuer","Alemanha"}, {"Marc-André ter Stegen","Alemanha"}, {"Kevin Trapp","Alemanha"},
            {"Bella Kotchap","Alemanha"}, {"Matthias Ginter","Alemanha"}, {"Christian Günter","Alemanha"}, {"Thilo Kehrer","Alemanha"},
            {"Lukas Klostermann","Alemanha"}, {"David Raum","Alemanha"}, {"Antonio Rüdiger","Alemanha"}, {"Nico Schlotterbeck","Alemanha"},
            {"Niklas Süle","Alemanha"}, {"Karim Adeyemi","Alemanha"}, {"Julian Brandt","Alemanha"}, {"Niclas Füllkrug","Alemanha"},
            {"Serge Gnabry","Alemanha"}, {"Leon Goretzka","Alemanha"}, {"Mario Götze","Alemanha"}, {"Ilkay Gündogan","Alemanha"},
            {"Kai Havertz","Alemanha"}, {"Jonas Hofmann","Alemanha"}, {"Joshua Kimmich","Alemanha"}, {"Youssoufa Moukoko","Alemanha"},
            {"Thomas Müller","Alemanha"}, {"Jamal Musiala","Alemanha"}, {"Leroy Sané","Alemanha"},
            // GRUPO E - COSTA RICA
            {"Keylor Navas","Costa Rica"}, {"Esteban Alvarado","Costa Rica"}, {"Patrick Sequeira","Costa Rica"},
            {"Francisco Calvo","Costa Rica"}, {"Juan Pablo Vargas","Costa Rica"}, {"Kendall Waston","Costa Rica"}, {"Óscar Duarte","Costa Rica"},
            {"Keysher Fuller","Costa Rica"}, {"Carlos Martínez","Costa Rica"}, {"Bryan Oviedo","Costa Rica"}, {"Ronald Matarrita","Costa Rica"},
            {"Yeltsin Tejeda","Costa Rica"}, {"Celso Borges","Costa Rica"}, {"Youstin Salas","Costa Rica"}, {"Roan Wilson","Costa Rica"},
            {"Gerson Torres","Costa Rica"}, {"Douglas López","Costa Rica"}, {"Jewison Bennette","Costa Rica"}, {"Álvaro Zamora","Costa Rica"},
            {"Anthony Hernández","Costa Rica"}, {"Brandon Aguilera","Costa Rica"}, {"Bryan Ruiz","Costa Rica"},
            {"Joel Campbell","Costa Rica"}, {"Anthony Contreras","Costa Rica"}, {"Johan Venegas","Costa Rica"},
            // GRUPO E - ESPANHA
            {"Unai Simón","Espanha"}, {"Robert Sánchez","Espanha"}, {"David Raya","Espanha"},
            {"Dani Carvajal","Espanha"}, {"César Azpilicueta","Espanha"}, {"Eric García","Espanha"}, {"Hugo Guillamón","Espanha"},
            {"Aymeric Laporte","Espanha"}, {"Pau Torres","Espanha"}, {"Jordi Alba","Espanha"}, {"José Gayà","Espanha"},
            {"Sergio Busquets","Espanha"}, {"Rodrigo","Espanha"}, {"Pedri","Espanha"}, {"Gavi","Espanha"}, {"Koke","Espanha"},
            {"Marcos Llorente","Espanha"}, {"Carlos Soler","Espanha"}, {"Álvaro Morata","Espanha"}, {"Ferrán Torres","Espanha"},
            {"Dani Olmo","Espanha"}, {"Nico Williams","Espanha"}, {"Pablo Sarabia","Espanha"}, {"Marco Asensio","Espanha"},
            {"Yeremy Pino","Espanha"}, {"Ansu Fati","Espanha"},
            // GRUPO E - JAPÃO
            {"Shuichi Gonda","Japão"}, {"Eiji Kawashima","Japão"}, {"Daniel Schmidt","Japão"},
            {"Yuto Nagatomo","Japão"}, {"Maya Yoshida","Japão"}, {"Takehiro Tomiyasu","Japão"}, {"Hiroki Sakai","Japão"},
            {"Yuta Nakayama","Japão"}, {"Shogo Taniguchi","Japão"}, {"Ko Itakura","Japão"}, {"Miki Yamane","Japão"}, {"Hiroki Ito","Japão"},
            {"Wataru Endo","Japão"}, {"Hidemasa Morita","Japão"}, {"Ao Tanaka","Japão"}, {"Daichi Kamada","Japão"},
            {"Junya Ito","Japão"}, {"Kaoru Mitoma","Japão"}, {"Takumi Minamino","Japão"}, {"Yuki Soma","Japão"}, {"Gaku Shibasaki","Japão"},
            {"Takefusa Kubo","Japão"}, {"Ritsu Doan","Japão"}, {"Daizen Maeda","Japão"}, {"Takuma Asano","Japão"}, {"Ayase Ueda","Japão"},
            // GRUPO F - BÉLGICA
            {"Koen Casteels","Bélgica"}, {"Thibaut Courtois","Bélgica"}, {"Simon Mignolet","Bélgica"},
            {"Toby Alderweireld","Bélgica"}, {"Zeno Debast","Bélgica"}, {"Wout Faes","Bélgica"}, {"Arthur Theate","Bélgica"},
            {"Jan Vertonghen","Bélgica"}, {"Timothy Castagne","Bélgica"}, {"Thomas Meunier","Bélgica"},
            {"Yannick Carrasco","Bélgica"}, {"Thorgan Hazard","Bélgica"}, {"Kevin De Bruyne","Bélgica"}, {"Leander Dendoncker","Bélgica"},
            {"Amadou Onana","Bélgica"}, {"Youri Tielemans","Bélgica"}, {"Axel Witsel","Bélgica"}, {"Hans Vanaken","Bélgica"},
            {"Charles De Ketelaere","Bélgica"}, {"Jérémy Doku","Bélgica"}, {"Eden Hazard","Bélgica"},
            {"Leandro Trossard","Bélgica"}, {"Dries Mertens","Bélgica"}, {"Loïs Openda","Bélgica"}, {"Michy Batshuayi","Bélgica"}, {"Romelu Lukaku","Bélgica"},
            // GRUPO F - CANADÁ
            {"James Pantemis","Canadá"}, {"Milan Borjan","Canadá"}, {"Dayne St. Clair","Canadá"},
            {"Samuel Adekugbe","Canadá"}, {"Joel Waterman","Canadá"}, {"Alistair Johnson","Canadá"}, {"Richie Laryea","Canadá"},
            {"Kamal Miller","Canadá"}, {"Steven Vitória","Canadá"}, {"Derek Cornelius","Canadá"},
            {"Liam Fraser","Canadá"}, {"Ismael Koné","Canadá"}, {"Mark-Anthony Kaye","Canadá"}, {"David Wotherspoon","Canadá"},
            {"Jonathan Osorio","Canadá"}, {"Atiba Hutchinson","Canadá"}, {"Stephen Eustáquio","Canadá"}, {"Samuel Piette","Canadá"},
            {"Tajon Buchanan","Canadá"}, {"Liam Millar","Canadá"}, {"Lucas Cavallini","Canadá"}, {"Iké Ugbo","Canadá"},
            {"Junior Hoilett","Canadá"}, {"Jonathan David","Canadá"}, {"Cyle Larin","Canadá"}, {"Alphonso Davies","Canadá"},
            // GRUPO F - MARROCOS
            {"Yassine Bono","Marrocos"}, {"Munir","Marrocos"}, {"Tagnaouti","Marrocos"},
            {"Achraf Hakimi","Marrocos"}, {"Noussair Mazraoui","Marrocos"}, {"Romain Saiss","Marrocos"}, {"Nayef Aguerd","Marrocos"},
            {"Achraf Dari","Marrocos"}, {"Jawad El-Yamiq","Marrocos"}, {"Yamia Attiat-Allal","Marrocos"}, {"Badr Benoun","Marrocos"},
            {"Sofyan Amrabat","Marrocos"}, {"Selim Amallah","Marrocos"}, {"Abdelhamid Sabiri","Marrocos"}, {"Azzedine Ounahi","Marrocos"},
            {"Bilel El Khannouss","Marrocos"}, {"Yahya Jabrane","Marrocos"}, {"Hakim Ziyech","Marrocos"}, {"Youssef En-Nesyri","Marrocos"},
            {"Sofiane Boufal","Marrocos"}, {"Aboukhlal","Marrocos"}, {"Ez Abdé","Marrocos"}, {"Amine Harit","Marrocos"},
            {"Ilias Chair","Marrocos"}, {"Abderazak Hamdallah","Marrocos"}, {"Walid Cheddira","Marrocos"},
            // GRUPO F - CROÁCIA
            {"Dominik Livaković","Croácia"}, {"Marko Ivusic","Croácia"}, {"Ivan Grbić","Croácia"},
            {"Domagoj Vida","Croácia"}, {"Dejan Lovren","Croácia"}, {"Borna Barišić","Croácia"}, {"Josip Juranovic","Croácia"},
            {"Josko Gvardiol","Croácia"}, {"Erik Sosa","Croácia"}, {"Nikola Stanišić","Croácia"}, {"Borna Sosa","Croácia"},
            {"Mario Pašalić","Croácia"}, {"Luka Modrić","Croácia"}, {"Mateo Kovačić","Croácia"}, {"Marcelo Brozović","Croácia"},
            {"Mario Pašalić (meio)","Croácia"}, {"Lovro Majer","Croácia"}, {"Kristijan Jakic","Croácia"}, {"Toni Šunjić","Croácia"},
            {"Ivan Perišić","Croácia"}, {"Andrej Kramarić","Croácia"}, {"Bruno Petković","Croácia"}, {"Mislav Oršić","Croácia"},
            {"Ante Budimir","Croácia"}, {"Marko Livaja","Croácia"},
            // GRUPO G - BRASIL
            {"Alisson Becker","Brasil"}, {"Ederson","Brasil"}, {"Weverton","Brasil"},
            {"Danilo","Brasil"}, {"Alex Sandro","Brasil"}, {"Dani Alves","Brasil"}, {"Alex Telles","Brasil"},
            {"Eder Militão","Brasil"}, {"Marquinhos","Brasil"}, {"Thiago Silva","Brasil"}, {"Bremer","Brasil"},
            {"Bruno Guimarães","Brasil"}, {"Casemiro","Brasil"}, {"Fabinho","Brasil"}, {"Fred","Brasil"}, {"Lucas Paquetá","Brasil"},
            {"Everton Ribeiro","Brasil"}, {"Neymar Jr","Brasil"}, {"Vinícius Júnior","Brasil"}, {"Antony","Brasil"}, {"Rodrygo","Brasil"},
            {"Raphinha","Brasil"}, {"Richarlison","Brasil"}, {"Pedro","Brasil"}, {"Gabriel Jesus","Brasil"}, {"Gabriel Martinelli","Brasil"},
            // GRUPO G - CAMARÕES
            {"André Onana","Camarões"}, {"Epassy","Camarões"}, {"Ngapandouetnbu","Camarões"},
            {"Nicolas Nkoulou","Camarões"}, {"Ebosse","Camarões"}, {"Jamal Tolo","Camarões"}, {"Caleb Mbaizo","Camarões"},
            {"Fai","Camarões"}, {"Castelletto","Camarões"}, {"Wooh","Camarões"}, {"Onguéné","Camarões"},
            {"Onana (meio)","Camarões"}, {"Gouet","Camarões"}, {"Andre-Frank Zambo Anguissa","Camarões"}, {"Ntcham","Camarões"},
            {"Kudus","Camarões"}, {"Nketiah","Camarões"}, {"Karl Toko Ekambi","Camarões"}, {"Aboubakar","Camarões"},
            {"Bryan Mbeumo","Camarões"}, {"Nsame","Camarões"}, {"Choupo-Moting","Camarões"}, {"Christian Bassogog","Camarões"}, {"Marou","Camarões"},
            // GRUPO G - SÉRVIA
            {"Marko Dmitrović","Sérvia"}, {"Predrag Rajković","Sérvia"}, {"Vanja Milinković-Savić","Sérvia"},
            {"Stefan Mitrović","Sérvia"}, {"Nikola Milenković","Sérvia"}, {"Strahinja Pavlović","Sérvia"}, {"Miloš Veljković","Sérvia"},
            {"Filip Mladenović","Sérvia"}, {"Strahinja Eraković","Sérvia"}, {"Srđan Babić","Sérvia"},
            {"Nemanja Gudelj","Sérvia"}, {"Sergej Milinković-Savić","Sérvia"}, {"Saša Lukić","Sérvia"}, {"Marko Grujić","Sérvia"},
            {"Filip Kostić","Sérvia"}, {"Uroš Račić","Sérvia"}, {"Nemanja Maksimović","Sérvia"}, {"Ivan Ilić","Sérvia"},
            {"Andrija Živković","Sérvia"}, {"Darko Lazić","Sérvia"}, {"Dušan Tadić","Sérvia"}, {"Aleksandar Mitrović","Sérvia"},
            {"Dušan Vlahović","Sérvia"}, {"Filip Đuričić","Sérvia"}, {"Luka Jović","Sérvia"}, {"Nemanja Radonjić","Sérvia"},
            // GRUPO G - SUÍÇA
            {"Gregor Kobel","Suíça"}, {"Diogo Köhn","Suíça"}, {"Yann Sommer","Suíça"}, {"Manuel Akanji","Suíça"},
            {"Eray Cömert","Suíça"}, {"Nico Elvedi","Suíça"}, {"Pablo Marí Fernandes","Suíça"}, {"Ricardo Rodríguez","Suíça"},
            {"Fabian Schär","Suíça"}, {"Silvan Widmer","Suíça"}, {"Michel Aebischer","Suíça"}, {"Breel Embolo","Suíça"},
            {"Renato Steffen","Suíça"}, {"Jérôme Omlin","Suíça"}, {"Haris Seferovic","Suíça"}, {"Xherdan Shaqiri","Suíça"},
            {"Edimilson Fernandes","Suíça"}, {"Steven Zuber","Suíça"}, {"Denis Zakaria","Suíça"},
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
            {"Diogo Costa","Portugal"}, {"José Sá","Portugal"}, {"Rui Patrício","Portugal"},
            {"Diogo Dalot","Portugal"}, {"João Cancelo","Portugal"}, {"António Silva","Portugal"}, {"Danilo Pereira","Portugal"},
            {"Pepe","Portugal"}, {"Rúben Dias","Portugal"}, {"Nuno Mendes","Portugal"}, {"Raphaël Guerreiro","Portugal"},
            {"João Palhinha","Portugal"}, {"Rúben Neves","Portugal"}, {"Bernardo Silva","Portugal"}, {"Bruno Fernandes","Portugal"},
            {"João Mário","Portugal"}, {"Matheus Nunes","Portugal"}, {"Otávio","Portugal"}, {"Vitinha","Portugal"}, {"William Carvalho","Portugal"},
            {"André Silva","Portugal"}, {"Cristiano Ronaldo","Portugal"}, {"Gonçalo Ramos","Portugal"}, {"João Félix","Portugal"},
            {"Rafael Leão","Portugal"}, {"Ricardo Horta","Portugal"},
            // GRUPO H - URUGUAI
            {"Sergio Rochet","Uruguai"}, {"Fernando Muslera","Uruguai"}, {"Sebastián Sosa","Uruguai"},
            {"Ronald Araújo","Uruguai"}, {"José Luis Rodríguez","Uruguai"}, {"Guillermo Varela","Uruguai"}, {"José María Giménez","Uruguai"},
            {"Sebastián Coates","Uruguai"}, {"Diego Godín","Uruguai"}, {"Martín Cáceres","Uruguai"}, {"Matías Viña","Uruguai"},
            {"Mathías Olivera","Uruguai"}, {"Matías Vecino","Uruguai"}, {"Rodrigo Bentancur","Uruguai"}, {"Federico Valverde","Uruguai"},
            {"Lucas Torreira","Uruguai"}, {"Manuel Ugarte","Uruguai"}, {"Facundo Pellistri","Uruguai"}, {"Nicolás De la Cruz","Uruguai"},
            {"Giorgian de Arrascaeta","Uruguai"}, {"Facundo Torres","Uruguai"}, {"Darwin Núñez","Uruguai"}, {"Luis Suárez","Uruguai"},
            {"Edinson Cavani","Uruguai"}, {"Maximiliano Gómez","Uruguai"}, {"Agustín Canobbio","Uruguai"}
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
    std::cout << "Novo usuário - digite nome: ";
    std::getline(std::cin, user);
    if (user.empty()) { std::cout << "Nome vazio. Abortando.\n"; return; }
    if (buscarUsuarioPorNome(user)) { std::cout << "Usuário já existe.\n"; return; }
    std::cout << "Digite senha: ";
    std::getline(std::cin, pass);
    Usuario u(user, pass);
    usuarios.push_back(u);
    std::cout << "Usuário criado.\n";
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
        std::cout << "1 - Novo Álbum\n2 - Acessar Álbum\n3 - Sair\nEscolha: ";
        std::string op;
        std::getline(std::cin, op);
        if (op == "1") criarUsuario();
        else if (op == "2") {
            std::string user, pass;
            std::cout << "Usuário: ";
            std::getline(std::cin, user);
            std::cout << "Senha: ";
            std::getline(std::cin, pass);
            Usuario* u = autenticar(user, pass);
            if (!u) { std::cout << "Credenciais inválidas.\n"; }
            else menuUsuario(*u);
        } else if (op == "3") {
            salvarDados();
            std::cout << "Dados salvos. Saindo.\n";
            return;
        } else {
            std::cout << "Opção inválida.\n";
        }
    }
}

void Album::menuUsuario(Usuario &u) {
    while (true) {
        std::cout << "\nUsuário: " << u.username << "\n";
        std::cout << "1 - Ver Álbum\n2 - Gerenciar a coleção\n3 - Abrir pacote de figurinhas\n4 - Voltar\nEscolha: ";
        std::string op;
        std::getline(std::cin, op);
        if (op == "1") verAlbum(u);
        else if (op == "2") gerenciarColecao(u);
        else if (op == "3") abrirPacote(u);
        else if (op == "4") { salvarDados(); return; }
        else std::cout << "Opção inválida.\n";
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
        std::cout << "\nPágina " << (page+1) << " de " << paginas << "\n";
        for (int i = start; i < end; ++i) {
            const Figurinha &f = catalogo[i];
            int st = u.status(f.id);
            std::cout << f.id << " - " << f.nome << " (" << f.selecao << ") - ";
            if (st == 1) std::cout << "COLADA\n";
            else if (st == 0) std::cout << "NA COLEÇÃO (COLAR)\n";
            else if (st == 2) std::cout << "DISPONÍVEL PARA TROCA\n";
            else std::cout << "NAO POSSUI\n";
        }
        std::cout << "n - próxima, p - anterior, v - voltar: ";
        std::string cmd;
        std::getline(std::cin, cmd);
        if (cmd == "n" && page+1 < paginas) page++;
        else if (cmd == "p" && page>0) page--;
        else if (cmd == "v") return;
        else std::cout << "Comando inválido.\n";
    }
}

void Album::gerenciarColecao(Usuario &u) {
    while (true) {
        std::cout << "\n--- Gerenciar Coleção ---\n";
        std::cout << "Figurinhas na coleção (id : status)\n";

        for (auto &p : u.colecao) {
            int id = p.first;
            int st = p.second;
            const Figurinha* f = buscarFigurinhaPorId(id);
            std::string nome = f ? f->nome : "Desconhecida";
            std::cout << id << " : " << nome << " - ";
            if (st == 0) std::cout << "NA COLEÇÃO\n";
            else if (st == 1) std::cout << "COLADA\n";
            else if (st == 2) std::cout << "DISPONÍVEL PARA TROCA\n";
        }

        std::cout << "\nOpções:\n";
        std::cout << "1 - Colar Figurinha\n";
        std::cout << "2 - Disponibilizar para troca\n";
        std::cout << "3 - Colar TODAS as figurinhas\n";
        std::cout << "4 - Propor troca\n";
        std::cout << "5 - Revisar solicitações de troca\n";
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
                std::cout << "Não pode colar essa figurinha.\n";
            }
        }

        else if (op == "2") {
            std::cout << "Informe id da figurinha a disponibilizar: ";
            std::string s;
            std::getline(std::cin, s);
            int id = std::stoi(s);
            if (u.possui(id) && u.status(id) != 1) {
                u.disponibilizarParaTroca(id);
                std::cout << "Figurinha disponível para troca.\n";
            } else {
                std::cout << "Não pode disponibilizar essa figurinha.\n";
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
            std::cout << "Opção inválida.\n";
        }
    }
}


void Album::abrirPacote(Usuario &u) {
    std::cout << "Abrindo pacote... você receberá 3 figurinhas.\n";
    int n = (int)catalogo.size();
    for (int k = 0; k < 3; ++k) {
        int id = 1 + (std::rand() % n);
        if (!u.possui(id)) {
            u.adicionar(id, 0);
            const Figurinha* f = buscarFigurinhaPorId(id);
            std::cout << "Recebeu: " << id << " - " << (f?f->nome:"Desconhecida") << " (" << (f?f->selecao:"") << ")\n";
        } else {
            const Figurinha* f = buscarFigurinhaPorId(id);
            std::cout << "Já possuía: " << id << " - " << (f?f->nome:"Desconhecida") << "\n";
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
            std::cout << "Usuário: " << other.username << " - figurinhas disponíveis:\n";
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
    std::cout << "Escolha usuário para propor troca (digite nome) ou vazio para cancelar: ";
    std::string parceiro; std::getline(std::cin, parceiro);
    if (parceiro.empty()) return;
    Usuario* p = buscarUsuarioPorNome(parceiro);
    if (!p) { std::cout << "Parceiro não encontrado.\n"; return; }
    std::cout << "Informe id da figurinha que deseja (do parceiro): ";
    std::string s1; std::getline(std::cin, s1);
    int deseja = std::stoi(s1);
    if (!p->possui(deseja) || p->status(deseja) != 2) { std::cout << "Parceiro não tem essa figurinha disponível.\n"; return; }
    std::cout << "Informe id da sua figurinha que oferece: ";
    std::string s2; std::getline(std::cin, s2);
    int oferta = std::stoi(s2);
    if (!u.possui(oferta) || u.status(oferta) == 1) { std::cout << "Você não tem essa figurinha disponível para oferta.\n"; return; }
    int idT = gerarIdTroca();
    trocas.emplace_back(idT, u.username, p->username, deseja, oferta, 0);
    std::cout << "Proposta enviada. ID da troca: " << idT << "\n";
}

void Album::revisarTrocas(Usuario &u) {
    std::vector<int> indices;
    for (size_t i=0;i<trocas.size();++i) {
        if (trocas[i].destinatario == u.username && trocas[i].status == 0) indices.push_back((int)i);
    }
    if (indices.empty()) { std::cout << "Nenhuma solicitação para revisar.\n"; return; }
    std::cout << "Solicitações pendentes:\n";
    for (size_t k=0;k<indices.size();++k) {
        Troca &t = trocas[indices[k]];
        std::cout << k << " - ID:" << t.id << " remetente:" << t.remetente << " pede:" << t.figDesejada << " oferece:" << t.figOfertada << "\n";
    }
    std::cout << "Escolha index da solicitação para revisar ou vazio para sair: ";
    std::string s; std::getline(std::cin, s);
    if (s.empty()) return;
    int idx = std::stoi(s);
    if (idx < 0 || idx >= (int)indices.size()) { std::cout << "Index inválido.\n"; return; }
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
        if (!remet || !dest) { std::cout << "Usuário envolvido não encontrado.\n"; t.status = 2; return; }
        if (!remet->possui(t.figOfertada) || remet->status(t.figOfertada) == 1) { std::cout << "Remetente não tem oferta válida. Cancelando.\n"; t.status = 2; return; }
        if (!dest->possui(t.figDesejada) || dest->status(t.figDesejada) == 1) { std::cout << "Você não tem a figurinha desejada colada ou indisponivel. Cancelando.\n"; t.status = 2; return; }
        dest->remover(t.figDesejada);
        remet->remover(t.figOfertada);
        remet->adicionar(t.figDesejada, 0);
        dest->adicionar(t.figOfertada, 0);
        t.status = 1;
        std::cout << "Troca aceita e aplicada.\n";
        return;
    } else {
        std::cout << "Comando inválido.\n";
    }
}

int Album::gerarIdTroca() {
    return proximaIdTroca++;
}

const Figurinha* Album::buscarFigurinhaPorId(int id) const {
    for (const auto &f : catalogo) if (f.id == id) return &f;
    return nullptr;
}