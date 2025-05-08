// sample C++ program
// Xu Cao
#include <iostream>
#include <chrono>
#include <string>
using namespace std;
enum FIRSTORLAST {
	FIRST,
	LAST
};

const int STUDENT_SIZE = 307;
struct Student {
	int Id;
	string Name;
	string City;
	char Gender;
	int Age;
	float GPA;
};
Student Find(int id, Student students[], int student_size);
Student Find(string name, Student students[], int student_size);
//Student Find(char gender, Student students[], int student_size, FIRSTORLAST location = FIRST);
//int GetAgeCount(char gender, Student students[], int student_size);
//Student Find(float gpa, Student students[], int student_size, FIRSTORLAST location = FIRST);
int main()
{
	Student  students[] =
	{
		{1,"Kiana Lor","Suzhou",'F',22,3.5},
		{2,"Joshua Lonaker","Santa Clarita",'M',22,2.9},
		{3,"Dakota Blanco","Oakland",'F',22,3.9},
		{4,"Natasha Yarusso","Castro Valley",'F',20,3.3},
		{5,"Brooke Cazares","São José dos Campos",'F',21,3.7},
		{6,"Rochelle Johnson","Indianapolis",'F',21,3.4},
		{7,"Joey Abreu","Shenyang",'M',22,3.7},
		{8,"Preston Suarez","São Paulo",'M',22,3.8},
		{9,"Lee Dong","Manila",'F',24,3.9},
		{10,"Maa'iz al-Dia","Istanbul",'M',22,2.4},
		{11,"Maja Nicholson","Dallas",'F',23,3.4},
		{12,"Sasha Jansen","Chicago",'F',21,1.7},
		{13,"Alexander Sherman","Omaha",'M',20,3.8},
		{14,"Edgar Sanchez","Tijuana",'M',23,3.7},
		{15,"Kolbi Strunk","Mission Viejo",'M',21,3.2},
		{16,"Brittany Sath","Tokyo",'F',21,4},
		{17,"Meggan Smith","Los Angeles",'F',21,2.9},
		{18,"Ericka Arreola","Mexico",'O',23,3.1},
		{19,"David Pulc","Toronto",'M',24,3.9},
		{20,"Kyle Luckey","Moreno Valley",'M',23,3.7},
		{21,"Rojesh Her","Tokyo",'M',22,3.8},
		{22,"David Weber","Peking",'M',20,3.9},
		{23,"Rachel Jambor","Chicago",'F',22,3.6},
		{24,"Mus'ab al-Moustafa","Rawalpindi",'M',23,3.8},
		{25,"Sila Nguyen","Hebi",'M',23,2.8},
		{26,"Samantha Hicks","Santa Barbara",'F',22,3.7},
		{27,"Angela Harding","Manteca",'F',22,3.1},
		{28,"Brandon Barbour","South Hill",'M',21,3.9},
		{29,"Reilly Wagar","Modesto",'F',23,3.4},
		{30,"Victoria Ibarra","Santo Domingo",'F',22,3.4},
		{31,"Dakota Wirth","Sacramento",'F',22,3.4},
		{32,"Lauren Klocker","Los Angeles",'F',22,2.3},
		{33,"Michael Benson","Phoenix",'M',21,3.8},
		{34,"Sean Rozga","Los Angeles",'M',21,3.4},
		{35,"Cody Vermeylen","Detroit",'M',23,3.3},
		{36,"Kinaana al-Jamail","Kanpur",'F',22,3.3},
		{37,"Daniel Garcia","Lima",'M',22,3.7},
		{38,"Katrina Saito","Tokyo",'F',22,3.8},
		{39,"Joshua Galloway","New York",'M',24,3.3},
		{40,"Aylin Mendoza","Mexico",'F',22,3},
		{41,"Sharon Fyfe","Los Angeles",'F',22,3.7},
		{42,"Afnaan el-Mohammed","New Delhi",'F',22,1.7},
		{43,"Jesse Williams","Moscow",'F',21,3.9},
		{44,"Kenny Fukushima","Tokyo",'M',22,3.9},
		{45,"Tawnie Glaisher","Fremont",'F',24,3.4},
		{46,"Britany Stevens","Lafayette",'F',23,3.6},
		{47,"Alan Trinh","Tokyo",'M',20,2.8},
		{48,"Zoe Kern","West Jordan",'F',22,2.1},
		{49,"Sidney Beavers","Los Angeles",'M',23,2.3},
		{50,"Miriam Aguilar","Mexicali",'F',22,3.6},
		{51,"Issac Mata","Tehuacán",'M',23,2.4},
		{52,"Hannah Uren","Los Angeles",'F',22,3.2},
		{53,"Zachary Bradley","Madrid",'M',21,3.5},
		{54,"Moira Buttitto","Los Angeles",'F',23,1.9},
		{55,"Nicole Humpal","Walnut Creek",'F',22,3.9},
		{56,"Georgia Williams","Memphis",'F',23,2.9},
		{57,"Connor Ferry","Charlotte",'M',23,3.1},
		{58,"Amanda Tatum","San Diego",'F',22,3.5},
		{59,"Cameron Steinberg","Los Angeles",'M',20,2.1},
		{60,"Shuraih el-Karim","Khalabat",'M',22,3.1},
		{61,"Katelyn Sharp","Los Angeles",'F',20,3.9},
		{62,"Colin Lemont","Shanghai",'M',21,3.6},
		{63,"Donald Nevins","San Jose",'M',23,3.6},
		{64,"Macaela Kadillak","Los Angeles",'F',20,2.7},
		{65,"Brittany Pratt","San Diego",'F',22,3},
		{66,"Cameron Hancock","Warsaw",'M',21,3.9},
		{67,"William Grevious","Stockton",'M',22,3.4},
		{68,"Lindsey Job","Los Angeles",'F',23,2.7},
		{69,"Gabrielle Smith","Seoul",'F',23,4},
		{70,"Allison Brink-Lomme","Portland",'F',24,2.8},
		{71,"Sheyenne Delgado-Manzanares","Manzanillo",'F',21,3.9},
		{72,"Joseph Smith","Sacramento",'M',21,3.7},
		{73,"Fikra al-Mina","Bombay",'F',21,3.1},
		{74,"Aurelia Davis Ingham","Roseville",'F',22,3.8},
		{75,"Taylor Elstun","San Diego",'F',21,2.3},
		{76,"Joseph Snider","Los Angeles",'M',21,3.2},
		{77,"Sourinthone Tran","Wuhan",'M',21,3.5},
		{78,"Ibrahim al-Sawaya","Manzil Tamim",'M',23,3.5},
		{79,"Alexandra Levy","Los Angeles",'F',23,3.1},
		{80,"Macie Nguyen","Tokyo",'F',23,3.1},
		{81,"Sean Tegtman","Kettering",'M',25,3.7},
		{82,"Casey Vanden Bos","Los Angeles",'M',22,2.7},
		{83,"Staci Maes","Mexico",'F',23,3.4},
		{84,"Luke Davey","Los Angeles",'M',26,3.8},
		{85,"Harper Wheeler-Marques","San Diego",'F',23,3.9},
		{86,"Sherleen Saravanan","Rangoon",'F',22,3.1},
		{87,"Myles Vaught","Waukegan",'M',21,3.4},
		{88,"Juan Guerrero Camacho","Mexico",'M',21,2.8},
		{89,"Lindsey Freund","New York",'F',20,3.3},
		{90,"Savannah Clark","Visalia",'F',20,2.8},
		{91,"Bradley Monsell","New York",'M',22,3},
		{92,"Daisha Schmidt","Boulder",'F',22,3.7},
		{93,"Airabella Koontz","Dallas",'F',22,2.7},
		{94,"Hailey Malle","Nizhniy Novgorod",'F',22,3.7},
		{95,"Devon Miranda","Pereira",'M',20,3.7},
		{96,"Danielle Nguyen","Tokyo",'F',23,3.3},
		{97,"Mateo Cisneros","Foz do Iguaçu",'M',23,3},
		{98,"William Pablo","Kashiwara",'M',24,2.9},
		{99,"Jason Hundsdorfer","Los Angeles",'M',20,3.9},
		{100,"Antonio Desai","Kawasaki",'M',22,2.2},
		{101,"Rachel Bakeman","Phoenix",'F',24,3.9},
		{102,"Mamdooh el-Moustafa","Karachi",'M',22,3.3},
		{103,"Lindsey Carter","Redwood City",'F',24,3.2},
		{104,"Duncan Kruse","Santa Ana",'M',23,3.7},
		{105,"Callahan Foster","Toronto",'O',22,3.2},
		{106,"Jamie Ortiz","Nueva San Salvador",'F',23,3.3},
		{107,"Ryan Barrett","Chicago",'M',20,3.7},
		{108,"Samuel Palmer","New York",'M',22,3.9},
		{109,"Riley Mcloughlin","Los Angeles",'M',23,3.6},
		{110,"Aimee Apelyan","Joliet",'F',24,3.3},
		{111,"Maryah Falloon","Phoenix",'F',23,3.9},
		{112,"Lucille Mitchell","Edmonton",'F',22,3.5},
		{113,"Christian Zambrano-Munoz","Mexicali",'M',23,3.1},
		{114,"Bryce Vaillancourt","Pomona",'M',22,3.7},
		{115,"Brandilyn Collins","Los Angeles",'F',21,3.6},
		{116,"Konner Gearhart","New York",'M',22,3.9},
		{117,"Andrew Houghton","Spokane",'M',22,3.2},
		{118,"Marisa Ramey","Mexico",'F',22,3.2},
		{119,"Magdalynne Noah","New York",'F',22,3.2},
		{120,"Megan Salamena","Los Angeles",'F',23,3.9},
		{121,"Meghan Arnold","Saint Petersburg",'F',24,4},
		{122,"James Rice","Toronto",'M',20,3.9},
		{123,"Wesley Nunn","Los Angeles",'M',23,3.9},
		{124,"Gareth Newkirk","Los Angeles",'M',21,4},
		{125,"Austin Harline","Las Vegas",'M',21,2.8},
		{126,"Courtney Martinez","Aguascalientes",'F',20,3.7},
		{127,"Alexandra Graham","Los Angeles",'F',22,3.4},
		{128,"Alexander Swearingen","Los Angeles",'M',22,3.9},
		{129,"Brandy Waldner","Zülpich",'F',20,3.2},
		{130,"Coleman Keelen","Callosa de Segura",'M',24,3.4},
		{131,"Casey Buhr","Phoenix",'M',21,3.7},
		{132,"Shauna Sneed","Burlingame",'F',19,2.7},
		{133,"Caitlin Dean","Philadelphia",'F',22,3.9},
		{134,"Andrew Kirin","Odessa",'M',25,3.8},
		{135,"Nadia Minks","Moscow",'F',24,3.8},
		{136,"Ivy Lucero","São Paulo",'F',24,3.9},
		{137,"Kevin Curry","Phoenix",'M',23,3.9},
		{138,"Charles Cramer","East Los Angeles",'M',23,3.1},
		{139,"Emily Warner","Lodi",'F',21,3.5},
		{140,"Mckenzie Haycock","Toronto",'F',20,3.8},
		{141,"Faviola Soto","Cortazar",'F',19,4},
		{142,"Stephen Wharton","Tuxtla Gutiérrez",'M',21,2.1},
		{143,"Alexandria Fortner","Phoenix",'F',20,3.9},
		{144,"Savannah Kivett","Colorado Springs",'F',21,3.8},
		{145,"Tanner Jones","Stockton",'M',23,3.9},
		{146,"Luisa Bautista","Mexico",'F',21,3.3},
		{147,"Juhaina al-Bilal","Dhaka",'F',20,3.9},
		{148,"Siena Ingram","Henderson",'F',21,3.8},
		{149,"Alondra Gardea Corral","Ensenada",'F',20,2.2},
		{150,"Vincent Webster","New York",'M',23,2},
		{151,"Abdul Jabbaar el-Abdul","Cairo",'M',20,1.5},
		{152,"Patrick Carnes","Mesa",'M',22,2.4},
		{153,"Shawn O Bryan","Fairfield",'M',23,2.9},
		{154,"Jenna Whitney","San Diego",'F',23,3.7},
		{155,"Kaitlin Krueger","Los Angeles",'F',24,3.7},
		{156,"Jaime Mikesell","Los Angeles",'F',20,3.9},
		{157,"Katelynn Andrie","Kansas City",'F',23,3},
		{158,"Maryn Manzanares","Laguna Hills",'F',21,3.9},
		{159,"Colleen Kohout","Philadelphia",'F',22,3.5},
		{160,"Daniel Spurlin","San Jose",'M',24,3.9},
		{161,"Trevor Bulba","Chicago",'M',21,3.9},
		{162,"Jordan Burkhamer","San Jose",'F',23,3},
		{163,"Rebecca Ah Fat","Tangshan",'F',22,1.8},
		{164,"Christopher Jacobo","Los Angeles",'M',21,3.4},
		{165,"Min Singal","Tokyo",'F',24,3.8},
		{166,"Corey Rademacher","Chernihiv",'M',22,3.1},
		{167,"Alexander Reed","Los Angeles",'M',22,3},
		{168,"Dalen Whiting","Carrollton",'F',23,2.8},
		{169,"Chelsea Persky","San Bernardino",'F',23,3.9},
		{170,"Karla Taylor","Mexico",'F',21,3.7},
		{171,"Kaden Yates","Salinas",'M',23,3.6},
		{172,"Maimoona el-Soliman","Ankara",'F',21,2.8},
		{173,"Aaqil el-Hashemi","Bangalore",'M',21,3.4},
		{174,"Sean Bruso","London",'M',19,3.2},
		{175,"Andrew Bishop","Los Angeles",'M',22,4},
		{176,"Zahraaa el-Yousef","Hospet",'F',22,3.9},
		{177,"Surya Ky","Tangshan",'M',21,3.7},
		{178,"George Mann","Moscow",'M',23,3.9},
		{179,"Latino Calderon","Hermosillo",'M',23,3.6},
		{180,"Baylen Cloutier","Phoenix",'M',22,3.9},
		{181,"Nicole Torres-Valadez","Rio de Janeiro",'F',24,3.9},
		{182,"Addie Villavicencio","San Jose",'F',20,4},
		{183,"Billy Jack Bestle","Baltimore",'M',22,3.7},
		{184,"Isabella Martinez","Bogotá",'F',23,2.6},
		{185,"Kimberly Thielke","Los Angeles",'F',21,3.8},
		{186,"Adrian Miguel-Gomez","Medellín",'M',22,3.7},
		{187,"Kayla Sales","Quincy",'F',22,2.1},
		{188,"Haafiza al-Attar","Rabat",'F',21,2.4},
		{189,"Juanita Medina","Mexico",'F',22,3.8},
		{190,"Emma Kim","Hengshui",'F',22,2.8},
		{191,"Mckayla Dopler","Kerkrade",'F',21,2.5},
		{192,"Jonathan Nevarez","Mexico",'M',23,2.7},
		{193,"Roger Redfern","Los Angeles",'M',21,3.9},
		{194,"Hannah Critchfield","New York",'F',21,3.5},
		{195,"Chue Fue Richter","Qiqihar",'M',23,3},
		{196,"Joshua Mesan","San Jose",'M',24,4},
		{197,"Dylan Bell","Tucson",'M',20,3.3},
		{198,"Troy White","New York",'M',22,4},
		{199,"Sabaaha al-Latif","Bangalore",'F',22,3.7},
		{200,"Grant Walden","San Diego",'M',22,3.8},
		{201,"Kitty Nguyen","Tokyo",'F',25,3.4},
		{202,"Tyler Kibel","Santa Ana",'M',24,4},
		{203,"Kyler Overboe","Chicago",'M',21,3.2},
		{204,"Alexander Lizama","Belo Horizonte",'M',21,3.9},
		{205,"Aaron Knott","Santa Ana",'M',23,3.2},
		{206,"Jessica Greenberg","Joplin",'F',23,3.6},
		{207,"Lexi Hatton","Los Angeles",'F',23,3.3},
		{208,"Jesse Hodapp","Danville",'M',21,3.8},
		{209,"Andrew Brunelli","New York",'M',23,3.4},
		{210,"Makenzie Swann","Stockton",'F',22,3.4},
		{211,"Carlos Anaya","Mexico",'M',24,3.7},
		{212,"Felipe Martinez Acosta","Santiago",'M',21,3.7},
		{213,"Emma Casias","Rochester",'F',22,3.2},
		{214,"Adolf Malik","Seoul",'M',21,3.1},
		{215,"Christian Chow","Handan",'M',21,2.6},
		{216,"Asad el-Yacoub","Thana",'M',22,2.6},
		{217,"Holly Marshall","San Francisco",'F',22,3},
		{218,"Brandilyn Hanselman","Chelyabinsk",'F',21,2},
		{219,"Nicole Patria","Chongqing",'F',24,3.9},
		{220,"Kyler Grieshaber","Cohoes",'M',22,3.6},
		{221,"Jasper Stang","Sacramento",'M',24,3.6},
		{222,"Anthony Visocsky","Santa Rosa",'M',21,3.4},
		{223,"Jake Seime","Reno",'M',22,2.4},
		{224,"Dasha Bannock Lee","San Diego",'O',20,2.8},
		{225,"Anthony Mcdevitt","Los Angeles",'M',24,3.1},
		{226,"Darby Focken","Hinsdale",'F',21,3.5},
		{227,"Abigail Gallegos","Belém",'F',24,3.4},
		{228,"Patricia Rockhold","San Francisco",'F',21,4},
		{229,"Kylie Schafer","Houston",'F',22,3.1},
		{230,"Katherine Beatty","Los Angeles",'F',19,4},
		{231,"Melissa Bickel","London",'F',22,3.6},
		{232,"Rachel Boh","Roseville",'F',22,3.8},
		{233,"Anna Yoshimura","Rizhao",'F',20,3.5},
		{234,"Joseph Hazelton","Oakland",'M',22,3.5},
		{235,"Tiffany Nguyen","Bangkok",'F',22,3.3},
		{236,"Ryan Tyler","Los Angeles",'M',20,3.7},
		{237,"Max Flores","Tijuana",'M',23,3.9},
		{238,"Veronica Tounzen","Tijuana",'F',21,3.8},
		{239,"Haley Ingrim-Hyrup","Fontana",'F',22,3.2},
		{240,"Kayla Sandefur","Los Angeles",'F',23,3.5},
		{241,"Rylee Onstott","Los Angeles",'O',21,4},
		{242,"Kelli De Bartolome","San Francisco",'F',23,3.4},
		{243,"Thomas Chanlynn","Bay Point",'M',22,2.4},
		{244,"Andrew Yelich","Boulder",'M',24,2},
		{245,"Dimitri Castillo","Dos Quebradas",'M',21,3.9},
		{246,"Matthew Strasburger","Los Angeles",'M',21,3.9},
		{247,"Vittoria Faulkner","Chicago",'F',22,4},
		{248,"Tyler Goetz","Los Angeles",'M',22,3.7},
		{249,"Tyler Weller","New York",'M',22,3.7},
		{250,"Terri Mergelman","Los Angeles",'F',23,2.7},
		{251,"Abigail Orgeron","Prior Lake",'F',23,3.2},
		{252,"Jessica Huynh","Seoul",'F',22,3.5},
		{253,"Kyle Blanscet","Sabattus",'M',23,3.8},
		{254,"Ronald Toth","Los Angeles",'M',23,2.7},
		{255,"Branden Cantrell","Phoenix",'M',23,2.7},
		{256,"Hannah Ratterman","Los Angeles",'F',23,3.5},
		{257,"Alexandria Winter","New York",'F',24,3.8},
		{258,"Ryan Russell","Vacaville",'M',22,3},
		{259,"Logan Nighswonger","Los Angeles",'M',21,2.7},
		{260,"Zaghlool al-Pasha","Deoria",'M',21,2.3},
		{261,"Madeline Kremke","Montgomery Village",'F',22,3.2},
		{262,"John Ferry","Long Beach",'M',21,3.8},
		{263,"Michelle Goldanloo","San Diego",'F',22,3.3},
		{264,"Ryan Heidebrecht","San Jose",'M',22,3.9},
		{265,"Murtidevi Chung","Tokyo",'F',21,2.9},
		{266,"Arely Rodriguez","Morelia",'F',21,3.9},
		{267,"Taylor Stone","Reno",'F',22,3},
		{268,"Melody Bowyer","Baytown",'F',21,3.2},
		{269,"Bryant Ronquillo","Aguascalientes",'M',20,4},
		{270,"Garrett Heim","Mobile",'M',20,4},
		{271,"Cody Amen","Las Vegas",'M',23,3.6},
		{272,"Jasmine Lopez","Guaxupé",'F',21,3.8},
		{273,"William Tierney","New York",'M',21,3.8},
		{274,"Matthew Sputh","Modesto",'M',22,3.2},
		{275,"Brenna Chapman","Las Vegas",'F',21,3.5},
		{276,"Blake Loughran","San Francisco",'M',21,4},
		{277,"Michael Melendrez","Shreveport",'M',22,3.4},
		{278,"Katie Abercrombie","Stockton",'F',21,3.8},
		{279,"Justin Krause","Independence",'M',21,3.9},
		{280,"Jennifer Hauge","Los Angeles",'F',23,2.6},
		{281,"Tiffanie Her","Tokyo",'F',22,3.4},
		{282,"Dyllan Paige","Sugar Land",'M',20,2.9},
		{283,"Cole Hathcoat","Lemoore",'M',23,2.4},
		{284,"Jesse Carballo","Bogotá",'M',20,3.8},
		{285,"Robert Podolski","Oakland",'M',22,3.7},
		{286,"Viridiana Ballesteros","Alfenas",'F',22,2.8},
		{287,"Michael Griffin","New York",'M',21,4},
		{288,"Chad Klemp","San Diego",'M',22,3.9},
		{289,"Weldon Hightower","New York",'M',20,2.6},
		{290,"Daniel Pierce","New York",'M',24,3.3},
		{291,"Michaela Schoenbeck","Rexburg",'F',22,3.9},
		{292,"Charles Prose","Miami",'M',24,3.7},
		{293,"Brittany Kemmerzell","New York",'F',23,3.2},
		{294,"Taryn Springfield","Vancouver",'F',20,3.5},
		{295,"Matthew Obourn","San Diego",'M',23,3.9},
		{296,"Travis Poss","Los Angeles",'M',23,2.3},
		{297,"Brittany Fernandez","Zamora",'F',23,3.9},
		{298,"Cody Smith","Charlotte",'M',23,3.8},
		{299,"Nicolas Papp","New York",'M',23,2.7},
		{300,"Christopher Inhulsen","Fort Worth",'M',23,3.1},
		{301,"Tessa Rawanduzy","Derby",'F',21,3.3},
		{302,"Vanessa Gonzalez","León",'F',24,3.3},
		{303,"Austin Haas","Columbus",'M',20,3.6},
		{304,"Madison Fithian","Los Angeles",'F',20,3.6},
		{305,"Zachary Mulvahill","Los Angeles",'M',20,3.2},
		{306,"Eliana Michelsen","Oakland",'F',23,3},
		{307,"Dane Whittemore","Toronto",'M',21,3.8}
	};


	// Prompt user how to search
	while (true)
	{
		int response;

		cout << "How do you want to search students?" << endl;
		cout << "1. Search by ID" << endl;
		cout << "2. Search by Name" << endl;
		cout << "3. Search by first one Gender" << endl;
		cout << "4. Search by last one Gender" << endl;
		cout << "5. Count by age" << endl;
		cout << "6. Search by first by GPA" << endl;
		cout << "7. Search by first by GPA" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter [0-7]";

		cin >> response;
		if (response == 0)
			exit(0);

		int studentID;
		string studentName;
		Student searchedStudent;
		// Write a switch statement to check the response and call the appropriate function.
		switch (response) {
			case 1:
				cout << "Please enter a student ID: " << endl;
				cin >> studentID;
				searchedStudent = Find(studentID, students, STUDENT_SIZE);
				break;
			case 2:
				cout << "Please enter a student name: " << endl;
				cin >> studentName;
				searchedStudent = Find(studentName, students, STUDENT_SIZE);
				break;
			default:
				cout << "Wrong input!";
		}

	}
	return 0;
}

Student Find(int id, Student students[], int student_size)
{
	Student ret = { 0, "Not found" };

	// Fill in the logic to find student by ID

	return ret;
}

Student Find(string name, Student students[], int student_size)
{
	Student ret = { 0, "Not found" };

	// Fill in the logic to find student

	return ret;
}

int CountByGender(char gender, Student students[], int student_size)
{
	int count = 0;
	// Fill in the logic to find count of gender count
	return count;
}

