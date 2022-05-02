#include "ObsługaWejściowa.h"

template<typename Typ>
void drukuj(Typ cos)
{ cout << cos << endl ;}

template<typename Typ>
int drukuj_bl(Typ cos)
{
  cerr << cos << endl;
  return 1;
}

int main(int argc, char const *argv[])
{
  if (argc != 2)
  { return drukuj_bl("Zbyt mało argumentów")  ;}
  // else if (argc > 3)
  // { return drukuj_bl("Za dużo argumentów")    ;}
  else
  {
    try
    {
      ObslugaWejsciowa O(argv[1]);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }


    // fstream file;
    // file.open("test.txt", ios::in);
    // if (file.is_open())
    // {

    //   while (not file.eof())
    //   {
    //     string line               ;
    //     smatch capturing_groups   ;
    //     std::getline(file, line)  ;

    //     string senders_phone_number = "", text = "";

    //     if (sms_flag)
    //     {

    //       vector<Recipient> recipients  ;
    //       while ((not file.eof()) and sms_flag)
    //       {
    //         if      (regex_match(line, capturing_groups, PHONE_LINE))
    //         {

    //           senders_phone_number = capturing_groups[2] ;
    //           found_senders_phone = true;
    //         }
    //         else if (regex_match(line, capturing_groups, TEXT_LINE))
    //         {
    //           text += capturing_groups[1] ;
    //           found_text = true                 ;
    //         }
    //         else if (regex_match(line, capturing_groups, RECIPIENT_LINE))
    //         {
    //           recipients.push_back(Recipient(capturing_groups[2], capturing_groups[4])) ;
    //           found_recipient = true  ;
    //           found_recipients += 1   ;
    //         }
    //         else
    //         {
    //           if (found_recipient and found_senders_phone and found_text)
    //           {
    //             SMS_message message(senders_phone_number, text, recipients);
    //             messages.push_back(message);
    //             found_messages += 1;
    //           }
    //           text.clear();
    //           recipients.clear();
    //           senders_phone_number.clear();
    //           sms_flag = false  ;
    //         }
    //         line = "";
    //         std::getline(file, line);
    //       }
    //     }
    //     sms_flag        = ( line == "SMS" );
    //   }

    //   file.close();
    //   cout << "Found messages: "    << found_messages   << endl ;
    //   cout << "Found recipients: "  << found_recipients << endl ;
    //   for (SMS_message message: messages)
    //   { cout << message << endl ;}
    // }
    // else
    // {
    //   cerr << "File does not exist" ;
    //   return 1;

    // }
  return 0;
  }
}
