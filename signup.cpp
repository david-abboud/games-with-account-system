#include "signup.h"
#include "mainwidget.h"




SignUp::SignUp(QWidget *parent) : QWidget(parent)
{
    // this->close();
     grid2 = new QGridLayout();
     signup = new QLabel("Sign up:");
     QFont f("Arial", 15, QFont::Bold);
     signup->setFont(f);
     grid2->addWidget(signup, 0,0);

     firstname = new QLabel ("First Name:");
     firstnametxt = new QLineEdit();
     grid2 -> addWidget(firstname, 1, 0);
     grid2 -> addWidget(firstnametxt, 1, 1);

     lastname = new QLabel("Last Name:");
     lastnametxt = new QLineEdit();
     grid2 -> addWidget(lastname, 2, 0);
     grid2 -> addWidget(lastnametxt, 2, 1);

     username = new QLabel("Username:");
     usernametxt = new QLineEdit();
     grid2->addWidget(username, 3,0);
     grid2->addWidget(usernametxt,3,1);

     password = new QLabel("Password:");
     passwordtxt = new QLineEdit();
     passwordtxt->setEchoMode(QLineEdit::Password);
     grid2->addWidget(password,4,0);
     grid2->addWidget(passwordtxt,4,1);

     dateOfBirth = new QLabel("Date of birth:");
     dateOfBirthTxt = new QDateEdit();
     grid2->addWidget(dateOfBirth,5,0);
     grid2->addWidget(dateOfBirthTxt,5,1);

     phoneNumber = new QLabel("Phone Number (+countryCode-phoneNumber): ");
     phoneNumberTxt = new QLineEdit();
     grid2->addWidget(phoneNumber,6,0);
     grid2->addWidget(phoneNumberTxt,6,1);

     profilePictureButton = new QPushButton("Insert profile picture");
     QObject::connect(profilePictureButton,SIGNAL(clicked(bool)), this, SLOT(insertProfilePicture()));
     grid2->addWidget(profilePictureButton,7,0);
     profilePicture = new QLabel();
     grid2->addWidget(profilePicture,8,1);


     mainPage = new QPushButton("Back to main page");
     QObject::connect(mainPage, SIGNAL(clicked(bool)), this, SLOT(backToMainPage()));
     grid2->addWidget(mainPage,9,0);

     gender = new QLabel("Gender:");

     refresh = new QPushButton("Sign up");
     QObject::connect(refresh, SIGNAL(clicked(bool)), this, SLOT(goToProfile2()));
     grid2 -> addWidget(refresh,9,1);

     ageBox = new QSpinBox();
     //textEdit = new QTextEdit();

     male = new QRadioButton("Male");
     female = new QRadioButton("Female");
     other = new QRadioButton("Other");

     group = new QGroupBox();

     box1 = new QVBoxLayout();

     QGridLayout *grid3 = new QGridLayout();
     grid3 -> addWidget(gender, 4,0);
     grid3 -> addWidget(male, 4,1);
     grid3 -> addWidget(female, 5,1);
     grid3 -> addWidget(other, 6,1);

     group -> setLayout(grid3);
     grid2->addWidget(group,8,0);

     box1 -> addItem(grid2);

     image.load(":/Pictures/Default.png");
     image = image.scaledToWidth(150, Qt::SmoothTransformation);
     profilePicture->setPixmap(QPixmap::fromImage(image));
     path = ":/Pictures/Default.png";

     setLayout(box1);
}

void SignUp::backToMainPage(){
     this->close();
     mainWidget *main1 = new mainWidget();

}
void SignUp::goToProfile2(){
    DataHandler *handler = new DataHandler();

    int upper = 0, lower = 0, number = 0;
    for (int i = 0; i < passwordtxt->text().length(); i++)
    {
        if (passwordtxt->text()[i] >= 'A' && passwordtxt->text()[i] <= 'Z')
            upper++;
        else if (passwordtxt->text()[i] >= 'a' && passwordtxt->text()[i] <= 'z')
            lower++;
        else if (passwordtxt->text()[i]>= '0' && passwordtxt->text()[i]<= '9')
            number++;
    }
     if(firstnametxt->text().size()==0
            || lastnametxt->text().size()==0
            || usernametxt->text().size()==0
            || passwordtxt->text().size()==0
            || dateOfBirthTxt->date().year() > 2013 // 8 year old +, for legal purposes
            || phoneNumberTxt->text().size()==0
            || (male->isChecked()==false && female->isChecked()==false && other->isChecked()==false)){
        Error *err = new Error("Please fill in all the required forms.");
        }

    else if (passwordtxt->text().size() < 8 || upper == 0 || lower == 0 || number == 0){
        Error* err = new Error("Password must contain at least 8 characters and contain at least one number, and upper and lower case letters.");
    }


    else if(phoneNumberTxt->text()[0] != '+' //assume country codes are 3 digits
                        || phoneNumberTxt->text()[4] != '-'){
        Error* err = new Error("Incorrect phone number format. Please follow given format.");
    }

    else if(handler->isUnique(usernametxt->text().toLower()) == false){
        Error *err = new Error("This username already exists.");
    }

    else{

        if(male->isChecked()){
            gender_string = "Male";
        }
        if(female->isChecked()){
            gender_string = "Female";
        }
        if(other->isChecked()){
            gender_string = "Other";
        }

        for(int i = 1; i < 4; i++){
            countryCode += phoneNumberTxt->text()[i];
        }

        handler->addObject(player(usernametxt->text(),  passwordtxt->text(),  firstnametxt->text(),
                                               lastnametxt->text(), gender_string,  dateOfBirthTxt->date(),  phoneNumberTxt->text(), path, countryCode));
        this->close();
        profilePage *prof = new profilePage(firstnametxt->text(), lastnametxt->text(), QString(path), countryCode);

    }
}
void SignUp::insertProfilePicture(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));

    if(QString::compare(fileName, QString()) != 0 ) {
        bool loaded = image.load(fileName);

        if(loaded){
            image = image.scaledToWidth(profilePicture->width(), Qt::SmoothTransformation);
            profilePicture->setPixmap(QPixmap::fromImage(image));
            path = fileName;
        }
        else{
            Error *err = new Error("Error.");
        }
    }
}
