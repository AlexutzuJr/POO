/* Să se scrie o clasă Mail_box cu datele membre email și capacitate (=numărul maxim de mesaje ce pot fi stocate). Aceasta va conține și un vector de obiecte din clasa Mail. Clasa Mail conține următoarele date membre de 
tipul std::string: sender, recipient, subject și body. Se vor citi de la tastatură, în ordine, următoarele informații:
- un șir de caractere reprezentând adresa de email proprie;
- un întreg reprezentând capacitatea maximă de stocare;
- un întreg reprezentând numărul de mesaje primite. Pentru fiecare mesaj primit se citesc următoarele date:
   - adresa de email a expeditorului;
   - adresa de email a destinatarului;
   - subiectul mesajului;
   - corpul mesajului;
- un întreg reprezentând o comandă, în funcție de care se vor executa diferite funcționalități:
1. check_inbox - se afișează toate mesajele destinate adresei reținute în obiectul Mail_box, în ordinea în care au fost introduse de la tastatură. Afișarea unui mesaj presupune afișarea următoarelor informații pe ecran, 
pe linii separate:
   a. Index: <index-ul din lista de mesaje>
   b. From: <sender>
   c. To: <recipient>
   d. Subject: <subject>
   e. <body>
   f. ---
2. check_outbox - se afișează toate mesajele trimise de către adresa reținută în obiectul Mail_box, în ordinea în care au fost trimise.
3. send - se citesc datele (fără expeditor) pentru un obiect Mail care va fi trimis către destinatar. Ulterior, se afișează pe ecran mesajele trimise.
4. reply - se citește de la tastatură un întreg reprezentând indexul mesajului din lista de mesaje din inbox căruia dorim să ii răspundem. Se citesc datele (subiectul si corpul mesajului) pentru un obiect Mail nou care 
va fi trimis ca răspuns pentru mesajul selectat. Ulterior, se afișează pe ecran mesajele trimise.
5. forward - se citește de la tastatură un întreg reprezentând indexul mesajului din lista de mesaje din inbox pe care dorim să îl redirecționăm. Se citește de la tastatură doar adresa de email către care facem 
redirecționarea, corpul și subiectul mesajului fiind preluate de la mesajul din inbox. Ulterior, se afișează pe ecran mesajele trimise. */


#include <iostream>
#include <limits>
#include <string>


//Clasa
class Mail_box;
class Mail;

class Mail{
  
    friend class Mail_box;
    
    //Date membre
    private:
        std::string sender;
        std::string recipient;
        std::string subject;
        std::string body;
        int index;
        
    //Constructor
    public:
        Mail(std::string sender=" ", std::string recipient=" ", std::string subject=" ", std::string body=" ", int index=-1): sender(sender), recipient(recipient), subject(subject), body(body), index(index){}
    
    //Getter
    public:
        std::string get_sender(){return sender;}
        std::string get_recipient(){return recipient;}
        std::string get_subject(){return subject;}
        std::string get_body(){return body;}
        
    //Setters
    public:
        void set_sender(std::string sender){this->sender=sender;}
        void set_recipient(std::string recipient){this->recipient=recipient;}
        void set_subject(std::string subject){this->subject=subject;}
        void set_body(std::string body){this->body=body;}
    
    //Functii
    public:
        void afisare_mail(){
            
            std::cout<<"Index:"<<index<<"\n";
            std::cout<<"From:"<< sender<<"\n";
            std::cout<<"To:"<< recipient<<"\n";
            std::cout<<"Subject:"<< subject<<"\n";
            std::cout<<"Body:"<<body<<"\n";
            std::cout<<"---"<<std::endl;
            
        }
    
};


class Mail_box{
    
    friend class Mail;
    
    //Date membre
    private:
        std::string email;
        int capacitate_maxima;
        Mail **mail_util;
        
    public:
        static int nr_mesaje;   //Numarul de mesaje actual
    
    //Consctructor
    public:
        Mail_box(std::string email=" ", int capacitate_maxima=0):email(email), capacitate_maxima(capacitate_maxima){
            this->mail_util = new Mail*[capacitate_maxima];
        }
        
    
    
    //Functii
    void adaugare_mail(std::string sender, std::string recipient, std::string subject, std::string body, int index){
        mail_util[index] = new Mail(sender, recipient, subject, body, index);
        nr_mesaje++;
        
    }
    
    
    //Getter
    public:
        std::string get_email(){return email;}
        static int get_nr_mesaje(){return nr_mesaje;}

        //Getter pentru ce este in Mail
        std::string get_sender_index(int index){return (*mail_util[index]).get_sender();}
        std::string get_recipient_index(int index){return (*mail_util[index]).get_recipient();}
        std::string get_subject_index(int index){return (*mail_util[index]).get_subject();}
        std::string get_body_index(int index){return (*mail_util[index]).get_body();}

    
    //Functii
    public:
    
        void check_inbox(){
            for(int i=0; i<nr_mesaje; i++)
                if(email == (*mail_util[i]).get_recipient())
                    (*mail_util[i]).afisare_mail();
        }
        
        void check_outbox(){
            for(int i=0; i<nr_mesaje; i++)
                if(email == (*mail_util[i]).get_sender())
                    (*mail_util[i]).afisare_mail();
        }
    
};


//Definim contor in fisier
int Mail_box::nr_mesaje=0;

//Functia main
int main(){
    
    //Initializare Date
    std::string mb_email;
    int mb_capacitate_maxima;
    int mb_numar_mesaje;               //Al catelea mesaj este
    std::string m_sender;
    std::string m_recipient;
    std::string m_subject;
    std::string m_body;
    
    int optiune;
    
    //Citim date
    std::getline(std::cin, mb_email);
    
    std::cin>>mb_capacitate_maxima;
    
    
    //Facem MailBoxul
    Mail_box yahoo(mb_email, mb_capacitate_maxima);
    
    //Facem Obiectele
    std::cin>>mb_numar_mesaje;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    for(int i=0; i<mb_numar_mesaje; i++){
        
        std::getline(std::cin, m_sender);
        std::getline(std::cin, m_recipient);
        std::getline(std::cin, m_subject);
        std::getline(std::cin, m_body);
        
        yahoo.adaugare_mail(m_sender, m_recipient, m_subject, m_body, i);
        
        
    }
    
    //Citim Optiunea
    std::cin >> optiune;
    
    //Optiuni
    if(optiune == 1){
        yahoo.check_inbox();
    }
        
    if(optiune == 2){
        yahoo.check_outbox();
    }
        
    if(optiune == 3){
        
        //Citim elementele
        std::getline(std::cin, m_sender);
        std::getline(std::cin, m_recipient);
        std::getline(std::cin, m_subject);
        std::getline(std::cin, m_body);
        
        //Adaugam noile elemente
        yahoo.adaugare_mail(yahoo.get_email(), m_recipient, m_subject, m_body, yahoo.get_nr_mesaje());
        
        yahoo.check_outbox();
    }
    
    if(optiune == 4){
        
        int index_mesaj;
        
        std::cin>>index_mesaj;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::getline(std::cin, m_subject);
        std::getline(std::cin, m_body);
        
        yahoo.adaugare_mail(yahoo.get_recipient_index(index_mesaj), yahoo.get_sender_index(index_mesaj), m_subject, m_body, yahoo.get_nr_mesaje());

        yahoo.check_outbox();
        
        
    }
    
    
    if(optiune == 5){
        
        int index_mesaj;
        
        std::cin>>index_mesaj;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::getline(std::cin, m_recipient);
        std::getline(std::cin, m_subject);
        
 
        
        yahoo.adaugare_mail(yahoo.get_email(), m_recipient, m_subject, yahoo.get_body_index(index_mesaj), yahoo.get_nr_mesaje());

        yahoo.check_outbox();
        
        
    }
    
    
    
    return 0;
    
}
