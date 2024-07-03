#include<iostream>
#include<fstream>
using namespace std;
//Helper Class
class Helper
{
public:
	static int StringLength(char* str)
	{
		int i = 0, count = 0;
		while (str[i] != '\0')
		{
			i++;
			count++;
		}
		return count;
	}
	static int StringLength(const char* str)
	{
		int i = 0, count = 0;
		while (str[i] != '\0')
		{
			i++;
			count++;
		}
		return count;
	}
	static void StringCopy(char*& dest, char*& str) {
		int length = StringLength(str);
		int i = 0;
		while (str[i] != '\0')
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = '\0';
	}
	static char* GetStringFromBuffer(char* buffer)
	{
		int length = StringLength(buffer);
		char* temp = new char[length + 1];
		StringCopy(temp, buffer);
		return temp;
	}

	static int returnIndex(char* buffer)
	{
		int length = Helper::StringLength(buffer);
		int index = 0;
		if (length == 2)
		{
			index = (int)buffer[1] - 49;
		}
		else if (length == 3)
		{
			index = ((int)buffer[1] - 48) * 10 + ((int)buffer[2] - 49);
		}
		else if (length == 5)
		{
			index = (int)buffer[4] - 49;
		}
		else
		{
			index = ((int)buffer[4] - 48) * 10 + ((int)buffer[5] - 49);
		}
		return index;
	}

	static bool CompareString(char* arr1, char* arr2)
	{
		int i = 0;
		while (arr2[i] != '\0')
		{
			if (arr1[i] != arr2[i])
			{
				return 0;
			}
			i++;
		}
		return true;
	}

	static bool CompareString2(const char* arr1, char* arr2)
	{
		int i = 0;
		int max = 0;
		int a = StringLength(arr1);
		int b = StringLength(arr2);
		if (a > b)
		{
			max = a;
		}
		else
		{
			max = b;
		}



		while (i <= max)
		{
			if (arr1[i] != arr2[i])
			{
				return 0;
			}
			i++;
		}
		return true;
	}

	static bool Possible(int i)
	{
		if (i < 10)  // Max 10 
			return true;
		else
			return false;
	}

	static void ShowTitle()
	{
		cout << "  \t\t*********  **********  ********  *********  ********    *********  *********  **       **      " << endl;
		cout << "  \t\t*********  **********  ********  *********  ********    *********  *********  **      **      " << endl;
		cout << "  \t\t**         **      **  **        **         **     **   **     **  **     **  **    **        " << endl;
		cout << "  \t\t**         **      **  **        **         **     **   **     **  **     **  **  **          " << endl;
		cout << "  \t\t*********  **********  **        *********  **********  **     **  **     **  ***             " << endl;
		cout << "  \t\t*********  **********  **        *********  **********  **     **  **     **  **  **          " << endl;
		cout << "  \t\t**         **      **  **        **         **      **  **     **  **     **  **    **        " << endl;
		cout << "  \t\t**         **      **  **        **         **      **  **     **  **     **  **     **        " << endl;
		cout << "  \t\t**         **      **  ********  *********  **********  *********  *********  **      **       " << endl;
		cout << "  \t\t**         **      **  ********  *********  **********  *********  *********  **       **       " << endl;
		cout << endl << endl << endl;
	}

	static void ShowLine()
	{
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
};

class Post;

//Object Class
class Object
{
private:

	char* ID;

public:

	Object()
	{
		ID = 0;
	}

	virtual ~Object()
	{
		if (ID)
			delete[] ID;
		ID = NULL;
	}

	void SetID(char* temp)
	{

		ID = Helper::GetStringFromBuffer(temp);
	}

	char* GetID()
	{
		return ID;
	}

	virtual void PrintID()
	{
		cout << ID;
	}
	virtual void PrintName() {

	}

	virtual void PrintListView()
	{
		cout << ID;
	}

	virtual void  AddposttoTimeline(Post* P) {
	}

	virtual void GetName() = 0;

	virtual void PrintObject() {
	};
};

class Post;
class Object;

//Date Class

class Date
{
private:

	int day;
	int month;
	int year;

public:

	static Date CurrentDate;

	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int _day, int _month, int _year)
	{
		day = _day;
		month = _month;
		year = _year;
	}
	void InputDate(ifstream& read)
	{
		read >> day >> month >> year;
	}
	void SetDate(int _day, int _month, int _year)
	{
		day = _day;
		month = _month;
		year = _year;
	}
	void PrintDate()
	{
		cout << "(";
		if (day <= 9)
		{
			cout << '0' << day << '/';
		}
		else
		{
			cout << day << '/';
		}
		if (month <= 9)
		{
			cout << '0' << month << '/';
		}
		else
		{
			cout << month << '/';
		}
		cout << year << ")\n";
	}

	~Date() {};   // Date Class has only static members so no point of destructors

	bool CheckDate(Date ptr)    //cheaking the post date with the current date
	{
		if (ptr.GetDay() == this->GetDay() || ptr.GetDay() - 1 == this->GetDay() && ptr.GetMonth() == this->GetMonth())
		{
			return 1;
		}
		return 0;
	}

	void SetDate(Date post)
	{
		day = post.day;
		month = post.month;
		year = post.year;
	}
	int GetDay()
	{
		return day;
	}

	int GetYear()
	{
		return year;
	}

	int GetMonth()
	{
		return month;
	}

	void PrintYear()
	{
		cout << year;
	}

	static Date GetCurrentDate()
	{
		return CurrentDate;
	}
};

Date Date::CurrentDate(14, 10, 2018);

//Activity Class

class Activity
{
private:

	char* Value;
	int TypeofActivity;

public:

	Activity()
	{
		Value = NULL;
		TypeofActivity = 0;
	}

	~Activity()
	{
		delete[]Value;
		Value = NULL;
	}

	void ReadData(ifstream& fin)
	{
		char temp[50] = { '\0' };
		fin >> TypeofActivity;
		fin.ignore(1);
		fin.getline(temp, 50);

		Value = Helper::GetStringFromBuffer(temp);

	}

	void PrintMood()
	{
		if (TypeofActivity == 1)
		{
			cout << "Feeling " << Value;
		}
		if (TypeofActivity == 2)
		{
			cout << "Thinking About " << Value;
		}
		if (TypeofActivity == 3)
		{
			cout << "Making " << Value;
		}
		if (TypeofActivity == 4)
		{
			cout << "Celebrating " << Value;
		}
	}

	char* GetValue()
	{
		return Value;
	}

};

//Comment Class.

class Comments
{
private:

	char* ID;
	char* Text;
	Object* Commentator;

public:

	static int TotalComments;

	Comments()
	{
		ID = NULL;
		Text = NULL;
		Commentator = NULL;
	}

	~Comments()
	{
		delete[]ID;
		delete[]Text;
		ID = NULL;
		Text = NULL;
		Commentator = NULL;
	}

	void ReadDataFromCommentfile(ifstream& obj)
	{
		char temp[100] = { '\0' };

		obj >> temp;
		ID = Helper::GetStringFromBuffer(temp);
	}

	void Loadtxt(ifstream& in)
	{
		char temp[100];
		in.getline(temp, 100);

		Text = Helper::GetStringFromBuffer(temp);
	}

	Object* GetCommentator()
	{
		return Commentator;
	}

	void SetNewCommentAndCommentator(char* txt, Object* comBy)
	{
		Text = txt;
		Commentator = comBy;
	}

	void AddCommentator(Object* ptr)
	{
		Commentator = ptr;
	}

	char* GetText()
	{
		return Text;
	}

	void PrintListView()
	{
		cout << "           ";
		Commentator->PrintName();
		cout << " wrote:" << '"';
		cout << Text << '"' << endl << endl;

	}

	char* GetCommentID()
	{
		return ID;
	}

};
int Comments::TotalComments = 0;

//Post Class
class Post
{
private:

	int PostType;
	char* PostID;
	Date SharedDate;
	Object* SharedBy;
	Object** LikedBy;
	Comments** CommentP;
	Activity* Mood;
	char* PostDescription;
	char* ValueofActivity;
	int CommentCount;
	int LikeCount;
	int SharedCount;
	int NoofComments;

public:

	static int TotalPosts;

	Post()
	{

		PostType = 0;
		PostID = 0;
		NoofComments = 0;
		SharedBy = NULL;

		LikedBy = new Object * [10];
		for (int i = 0; i < 10; i++)
			LikedBy[i] = NULL;
		PostDescription = NULL;
		ValueofActivity = NULL;
		CommentP = new Comments * [10];
		for (int i = 0; i < 10; i++)
		{
			CommentP[i] = NULL;
		}
		Mood = NULL;
		CommentCount = 0;
		LikeCount = 0;
		SharedCount = 0;


	}

	~Post()
	{
		cout << PostID << " deleted" << endl;
		delete[]PostID;
		delete[]PostDescription;
		delete[]ValueofActivity;
		PostID = NULL;
		PostDescription = NULL;
		ValueofActivity = NULL;
		delete[]CommentP;
		CommentP = NULL;
		Mood = NULL;
		LikedBy = NULL;
		SharedBy = NULL;

	}

	void ReadDataFromPostFile(ifstream& Read, Post* PostData)
	{

		char temp[100] = { '\0' };
		Read >> PostData->PostType;
		Read >> temp;
		PostData->PostID = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 100; i++)
		{
			temp[i] = '\0';
		}
		PostData->SharedDate.InputDate(Read);
		Read.ignore(1);
		Read.getline(temp, 100);
		PostData->PostDescription = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 100; i++)
		{
			temp[i] = '\0';
		}

		if (PostType == 2)
		{
			PostData->Mood = new Activity;      // Without This it was throwing Exception that this is NULLPTR
			PostData->Mood->ReadData(Read);
		}

	}

	void SetLiked(Object* L)
	{

		if (Helper::Possible(LikeCount))
		{
			for (int i = 0; i < 10; i++)
			{
				if (LikedBy[i] == NULL)
				{
					LikedBy[i] = L;
					LikeCount++;
					break;
				}
			}
		}
		else
		{
			cout << "YOU HAVE REACHED YOUR LIKE LIMIT\n";
		}

	}

	Post* operator=(const Post rhs)
	{
		if (this != &rhs)
		{
			PostID = Helper::GetStringFromBuffer(rhs.PostID);
			PostDescription = Helper::GetStringFromBuffer(rhs.PostDescription);
			CommentP = rhs.CommentP;
		}
		return this;
	}

	/*Object** GetLikedBy();
	void AddComment(Comments*);
	void SetCommentstoPost(Comments**);*/

	void SetShared(Object* S)
	{
		SharedBy = S;
	}

	bool CheckDateofPost()
	{
		if (this->GetSharedDate().CheckDate(Date::GetCurrentDate()) == 1)
		{
			return 1;
		}
		return 0;
	}

	void AddNewComment(char* text, Object* ptr)
	{
		CommentP[NoofComments] = new Comments;
		CommentP[NoofComments]->SetNewCommentAndCommentator(text, ptr);
		NoofComments++;
	}

	void PrintPost()
	{
		if (Mood != NULL)
		{
			SharedBy->PrintName();
			Mood->PrintMood();
			cout << " " << PostDescription << "";
			SharedDate.PrintDate();
			for (int i = 0; i < NoofComments; i++)
			{
				CommentP[i]->PrintListView();
			}
		}
		else
		{
			SharedBy->PrintName();
			cout << " " << PostDescription;
			SharedDate.PrintDate();
			for (int i = 0; i < NoofComments; i++)
			{
				CommentP[i]->PrintListView();
			}
		}
	}

	void ViewLikedBy()
	{
		cout << "Command: ViewLikedList(";
		cout << this->GetID() << ")" << "\n";
		cout << "\n";

		for (int i = 0; i < LikeCount; i++)
		{
			LikedBy[i]->PrintObject();
		}
		cout << "\n";

	}

	void Likepost(Object* ptr)
	{
		cout << "Command: " << "LikedPost(";
		cout << this->GetID() << ")" << "\n";

		for (int i = 0; ; i++)
		{
			if (LikedBy[i] == NULL)
			{
				LikedBy[i] = ptr;
				i++;
				//LikedBy[i] = NULL;
				break;
			}
		}
	}


	void Addcomment(Comments* ptr)
	{
		for (int i = 0; ; i++)
		{
			if (CommentP[i] == NULL)
			{
				CommentP[i] = ptr;
				i++;
				CommentP[i] = NULL;
				break;
			}
		}
	}

	Comments* GetCommentArr(int i)
	{
		return CommentP[i];
	}

	void ViewComments(Post ptr[])
	{
		int i = 0;
		ptr->GetID();
		while (ptr->GetCommentArr(i) != NULL)
		{
			Object* n = ptr->GetCommentArr(i)->GetCommentator();
			cout << "\t\t";
			n->GetName();
			cout << " wrote: ";

			cout << ptr->GetCommentArr(i)->GetText();
			cout << endl;
			i++;
		}
	}

	int GetLikecount()
	{
		return LikeCount;
	}

	void SetLikeCount(int _count)
	{
		LikeCount = _count;
	}

	Object* GetShared()
	{
		return SharedBy;
	}

	Date& GetSharedDate()
	{
		return SharedDate;
	}

	Comments** GetComment()
	{
		return CommentP;
	}

	Comments* Get_Comm(int i)
	{
		return CommentP[i];
	}

	void SetSharedDate(Date obj)
	{
		SharedDate = obj;
	}

	int GetPostedDay()
	{
		return SharedDate.GetDay();
	}

	void SetCommentCount(int C)
	{
		CommentCount = C;
	}

	int GetCommentCount()
	{
		return CommentCount;
	}

	void SetPostDescription(char* post)
	{
		PostDescription = Helper::GetStringFromBuffer(post);

	}

	void PrintPostDescription()
	{
		cout << "\t\t" << this->PostDescription;
		cout << ".....";
	}

	Activity* GetActivity()
	{
		return Mood;
	}

	char* GetPostDescription()
	{
		return PostDescription;
	}

	void PrintName() {};  //<<<<<<<<<<<<-------------------------------------------

	void PrintDetailedView()
	{
		if (SharedBy != NULL)
		{
			SharedBy->PrintName();
			cout << "shared :";
		}
		cout << "\"" << PostDescription << "\"" << "...";
		SharedDate.PrintDate();

		if (CommentP != NULL)
		{
			for (int i = 0; i < CommentCount; i++)
				CommentP[i]->PrintListView();
		}
	}

	void PrintListView()
	{
		cout << "\"" << PostDescription << "\"" << "...";
		SharedDate.PrintDate();
	}

	char* GetID()
	{
		return PostID;
	}

	virtual void Print()
	{

		cout << "----";
		SharedBy->GetName();

		if (this->GetActivity() != NULL)
		{
			cout << " is ";
			this->GetActivity()->PrintMood();
			cout << endl;
		}
		else
		{
			cout << " shared: ";
		}
		this->PrintPostDescription();
		this->SharedDate.PrintDate();
		cout << endl;
		ViewComments(this);
		cout << endl;




	}

	void GetSharedByName()
	{
		SharedBy->PrintName();
	}

};
int Post::TotalPosts = 0;

class Post;

//Memory Class 

class Memory : public Post
{
private:

	Post* OGPost;
	char* ShareText;

public:

	Memory()
	{
		OGPost = NULL;
		ShareText = NULL;
	}

	Memory(Post* p, char* txt, Object* sharedBy)
	{
		OGPost = p;
		ShareText = Helper::GetStringFromBuffer(txt);
		SetShared(sharedBy);
		SetSharedDate(Date::CurrentDate);
	}

	void SetOGPost(Post* P)
	{
		OGPost = P;
	}

	Post* Get_memory()
	{
		return OGPost;
	}

	void Print()
	{
		cout << "~~~";
		GetSharedByName();
		cout << " shared a memory ~~~";
		GetSharedDate().PrintDate();
		cout << endl << '"' << ShareText << '"' << endl;
		cout << "\t\t( ";
		(GetSharedDate().PrintDate(), OGPost->GetSharedDate().PrintDate());
		cout << "(" << Date::CurrentDate.GetYear() - OGPost->GetSharedDate().GetYear() << " Years Ago )\n\n";
		OGPost->PrintPost();
	}

	~Memory()
	{
		OGPost = NULL;
		delete[] ShareText;
		ShareText = NULL;
	}
};

//Page Class

class Pages : public Object
{
private:

	char* PageID;
	char* PageName;
	Post** Timeline;
	int totalPost;
public:
	static int TotalPages;
	Pages()
	{
		PageID = NULL;
		PageName = NULL;
		totalPost = 0;
		Timeline = new Post * [10];
		for (int i = 0; i < 10; i++)
		{
			Timeline[i] = NULL;
		}
	}

	~Pages()
	{
		delete[]PageID;
		delete[]PageName;
		PageID = NULL;
		PageName = NULL;
		delete[]Timeline;
		Timeline = NULL;
	}
	void PrintID()
	{
		cout << PageID;
	}
	void PrintName() {
		cout << PageName << " ";
	}
	void ReadDataFromPageFile(ifstream& Read)
	{
		char temp[100] = { '\0' };
		Read >> temp;
		PageID = Helper::GetStringFromBuffer(temp);
		SetID(PageID);
		for (int i = 0; i < 100; i++)
		{
			temp[i] = '\0';
		}
		Read.getline(temp, 100);
		PageName = Helper::GetStringFromBuffer(temp);
	}

	static Pages* SetLikedPage(Pages** Pages, char* ID)
	{
		int i;
		for (i = 0; i < Pages::TotalPages; i++)
		{
			if (Helper::CompareString(Pages[i]->PageID, ID))
			{
				return Pages[i];
				break;
			}
		}
	}

	char* GetPageID()
	{
		return this->PageID;
	}

	void PrintObject()
	{
		cout << this->PageID;
		cout << " - ";
		this->PrintName();
	}

	void PrintPageListView()
	{
		cout << PageID << " - " << PageName << endl;
	}
	char* GetPageName()
	{
		return this->PageName;
	}

	void AddposttoTimeline(Post* Ptr)     //Adding post to timeline
	{
		Timeline[totalPost] = new Post;
		Timeline[totalPost] = Ptr;
		totalPost++;
	}

	void ShowrPostByPage()
	{
		for (int i = 0; i < totalPost; i++)
		{
			if (Timeline[i]->CheckDateofPost() == 1)

				Timeline[i]->Print();
		}
	}

	void GetName()
	{
		cout << this->GetPageName() << endl;
	}

	void ViewTimeLine()
	{
		for (int i = 0; i < this->totalPost; i++)
		{
			Timeline[i]->PrintDetailedView();
		}
	}

	void ViewComments(Post ptr[])
	{
		int i = 0;
		while (ptr->Get_Comm(i) != NULL)
		{
			cout << "\n";
			Object* n = ptr->Get_Comm(i)->GetCommentator();

			n->GetName();
			cout << " wrote: ";
			cout << ptr->Get_Comm(i)->GetText();

			i++;
		}
	}

	void Viewpage()     //To view the page
	{
		cout << this->PageName << "\n" << "\n";

		int i = 0;

		while (this->Timeline[i] != NULL)
		{
			cout << "----" << this->PageName;
			cout << " is ";
			if (Timeline[i]->GetActivity() != NULL)
			{

				Timeline[i]->GetActivity()->PrintMood();
				cout << " " << Timeline[i]->GetActivity()->GetValue();
				cout << "\n";
			}
			cout << "\"" << Timeline[i]->GetPostDescription() << "\"" << "............";
			Timeline[i]->GetSharedDate().PrintDate();
			ViewComments(Timeline[i]);
			cout << "\n" << "\n";
			i++;
		}
		cout << "-----------------------------------------------------------------" << "\n";
		cout << "\n";
	}

};
int Pages::TotalPages = 0;

class Users : public Object
{
	char* UserID;
	char* UserFName;
	char* UserLName;
	char** UserFriends;
	Pages** LikedPagesList;
	Users** FriendList;
	Post** Timeline;
	int NoofFriends;
	int NoofLikedPages;
	int TotalPosts;
	int CountT;

public:

	static int TotalUsers;
	Users()
	{
		UserID = NULL;
		UserFName = NULL;
		UserLName = NULL;
		UserFriends = NULL;
		FriendList = NULL;

		Timeline = new Post * [10];
		for (int i = 0; i < 10; i++)
		{
			Timeline[i] = new Post;
			Timeline[i] = 0;
		}

		LikedPagesList = NULL;
		NoofFriends = 0;
		NoofLikedPages = 0;
		TotalPosts = 0;
		CountT = 0;
	}

	~Users()
	{
		delete[]UserID;
		delete[]UserFName;
		delete[]UserLName;

		delete[]UserFriends;

		delete[] FriendList;
		delete[]LikedPagesList;
		delete[]Timeline;
	}

	void ShowwTitleOnly()
	{
		cout << GetUserFName() << " " << GetUserLName() << " ->   Liked Page List" << endl << endl;
	}

	void ReadDataFromUserFile(ifstream& Read, Pages** PageInfo, int tPages, Users* UserData)
	{
		UserData = new Users; // It was Crashing if we Allocate Memory in the Previous Function

		char temp[20] = { '\0' };
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;

		this->UserID = Helper::GetStringFromBuffer(temp);
		SetID(UserID);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		this->UserFName = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		this->UserLName = Helper::GetStringFromBuffer(temp);
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}
		Read >> temp;
		this->UserFriends = new char* [20];
		int i;
		for (i = 0; temp[0] != '-' || temp[1] != '1'; i++)
		{
			this->UserFriends[i] = Helper::GetStringFromBuffer(temp);
			Read >> temp;
		}
		this->NoofFriends = i;
		for (int i = 0; i < 20; i++)
		{
			temp[i] = '\0';
		}

		this->LikedPagesList = new Pages * [10];
		Read >> temp;
		int j;
		for (j = 0; temp[0] != '-' || temp[1] != '1'; j++)
		{
			this->LikedPagesList[j] = new Pages;
			this->LikedPagesList[j] = Pages::SetLikedPage(PageInfo, temp);
			Read >> temp;
		}
		this->NoofLikedPages = j;
	}

	void ShowTitleOnly()
	{
		cout << GetUserFName() << " " << GetUserLName() << " ->   Friend List" << endl << endl;
	}


	void ViewFriendList()
	{
		cout << " Command: View Friend List" << endl;
		Helper::ShowLine();
		//cout << this->GetUserFName() << " " << this->GetUserLName() << " ->   Friend List" << endl << endl;
		ShowTitleOnly();
		for (int i = 0; i < NoofFriends; i++)
		{
			//cout << this->FriendList[i]->GetUserID() << "\t " << FriendList[i]->GetUserFName() << " " << FriendList[i]->GetUserLName() << endl;
			FriendList[i]->PrintListView();
			cout << endl;

		}
	}

	void ViewLikedPages()
	{
		cout << " Command: View Liked Pages" << endl;
		Helper::ShowLine();
		ShowwTitleOnly();
		//cout << this->GetUserFName() << " " << this->GetUserLName() << " ->   Liked Pages" << endl << endl;
		for (int j = 0; j < this->NoofLikedPages; j++)
		{
			//cout << this->LikedPagesList[j]->GetPageID() << "\t" << LikedPagesList[j]->GetPageName() << endl;
			this->LikedPagesList[j]->PrintPageListView();
		}
	}

	void PrintObject()
	{
		this->UserID;
		cout << " - " << this->GetUserFName() << " " << this->GetUserLName();

	}

	char* GetUserFName()
	{
		return this->UserFName;
	}
	char* GetUserLName()
	{
		return this->UserLName;
	}
	char* GetUserID()
	{
		return this->UserID;
	}
	void PrintID()
	{
		cout << UserID;
	}
	void PrintName() {
		cout << UserFName << " " << UserLName << " ";
	}
	void LikeAPost(Post* postID)
	{
		Timeline[CountT] = postID;
		++CountT;
		postID->Likepost(this);
	}

	int GetNoofFriends()
	{
		return this->NoofFriends;
	}

	int GetNoofLikedPages()
	{
		return this->NoofLikedPages;
	}

	void PrintListView()
	{
		cout << UserID << " - " << UserFName << " " << UserLName << endl;
	}

	static void SetFriends(Users** usersInfo, int TotalUsers)
	{
		char* ID;
		for (int i = 0; i < TotalUsers; i++)
		{
			usersInfo[i]->FriendList = new Users * [usersInfo[i]->NoofFriends];
			for (int j = 0; j < usersInfo[i]->NoofFriends; j++)
			{
				ID = usersInfo[i]->UserFriends[j];
				for (int k = 0; k < TotalUsers; k++)
				{
					if (Helper::CompareString(usersInfo[k]->UserID, ID))
					{
						usersInfo[i]->FriendList[j] = new Users;
						usersInfo[i]->FriendList[j] = usersInfo[k];
						break;
					}
				}
			}
		}
	}

	void AddposttoTimeline(Post* Ptr)
	{
		//Timeline[TotalPosts] = new Post;
		Timeline[TotalPosts] = Ptr;
		TotalPosts++;
	}

	void GetName() {
		cout << this->GetUserFName() << " " << this->GetUserLName();
	}

	void ShowPostByUser()
	{
		for (int i = 0; i < TotalPosts; i++)
		{
			if (Timeline[i]->CheckDateofPost() == 1)
			{
				Timeline[i]->Print();
			}
		}
	}

	void viewTimeline()      //To view timeline
	{
		this->GetName();
		cout << " ->\t Timeline" << "\n";

		cout << "\n";
		// this->viewpost();

		for (int i = 0; i < TotalPosts; i++)
		{
			Timeline[i]->Print();

		}

	}

	void ViewHome()
	{
		GetName();
		cout << " -> \tHome Page" << "\n";

		cout << "\n";

		for (int i = 0; i < NoofFriends; i++)
		{

			FriendList[i]->ShowPostByUser();
		}

		for (int i = 0; i < NoofLikedPages; i++)
		{
			LikedPagesList[i]->ShowrPostByPage();
		}
		cout << "\n";
	}

	void ViewYourMemories()
	{
		cout << "We hope you enjoy looking back and sharing your memories of Facebook, from the most recent to those long ago" << endl;
		cout << "On this day" << endl;
		for (int i = 0; i < CountT; i++)
		{
			if (Timeline[i]->CheckDateofPost())
			{
				Timeline[i]->PrintPost();
			}
		}
	}

	void ShareMemory(char* txt, Post* p)
	{
		Memory* memory = new Memory{ p,txt,this };			//this = Post Pointer
		AddposttoTimeline(memory);
	}
};
int Users::TotalUsers = 0;

//FaceBook Class

class Facebook :public Users
{
private:
	Users** UserInfo;
	Pages** PageInfo;
	Post** PostInfo;
	Users* CurrentUser;
public:
	//static Date CurrentDate;

	Facebook()
	{
		UserInfo = NULL;
		PageInfo = NULL;
		PostInfo = NULL;
		CurrentUser = NULL;

	}

	~Facebook()
	{
		for (int i = 0; i < Users::TotalUsers; i++)
		{
			if (UserInfo[i])
				delete UserInfo[i];
		}
		delete[] UserInfo;

		for (int i = 0; i < Pages::TotalPages; i++)
		{
			if (PageInfo[i])
				delete PageInfo[i];
		}
		delete[] PageInfo;
		delete[]PostInfo;
	}

	void LoadData()
	{
		ifstream Read;
		LoadPages(Read);
		LoadUsers(Read);
		LoadPost(Read);
		LoadComments(Read);

	}

	//Search the id of the obj
	Object* SearchobjByID(const char str[])
	{

		if (str[0] == 'u')
		{
			for (int i = 0; i < Users::TotalUsers; i++)
			{
				if (Helper::CompareString2(str, UserInfo[i]->GetUserID()) == 1)
				{
					return UserInfo[i];
				}
			}
		}
		if (str[0] == 'p')
		{
			for (int i = 0; i < Pages::TotalPages; i++)
			{
				if (Helper::CompareString2(str, PageInfo[i]->GetPageID()) == 1)
				{
					return PageInfo[i];
				}
			}
		}

		return NULL;
	}

	//Search post by ID
	Post* SearchpostbyID(const char str[])
	{
		if (str[0] == 'p')
		{
			for (int i = 0; i < Post::TotalPosts; i++)
			{
				if (Helper::CompareString2(str, PostInfo[i]->GetID()) == 1)
				{
					return PostInfo[i];
				}
			}
		}
		return NULL;
	}

	void LoadPages(ifstream& Read)
	{
		Read.open("PageList.txt");
		if (Read.is_open())
		{

			Read >> Pages::TotalPages;
			PageInfo = new Pages * [Pages::TotalPages];
			int i = 0;
			while (!Read.eof() && i < Pages::TotalPages)// 2nd Condition is for cases when it is still reading after end of file
			{
				cout << "Pages" << i << endl;
				PageInfo[i] = new Pages;
				PageInfo[i]->ReadDataFromPageFile(Read);
				i++;
			}
			Read.close();
		}
		else
		{
			cout << "Page File was not Properly Opened" << endl;
		}
	}

	void LoadPost(ifstream& Read)
	{
		Read.open("Posts.txt");
		char temp[100] = { '\0' };
		Object* Shared_By;
		Object* Liked_By;
		if (Read.is_open())
		{
			Read >> Post::TotalPosts;
			PostInfo = new Post * [Post::TotalPosts];
			int i = 0;
			while (!Read.eof() && i < Post::TotalPosts)
			{
				cout << "Post" << i << endl;
				PostInfo[i] = new Post;
				PostInfo[i]->ReadDataFromPostFile(Read, PostInfo[i]);
				Read >> temp;    //  Reading Shared User/Page 
				if (temp[0] == 'u')
				{
					char* ID = Helper::GetStringFromBuffer(temp);
					Object* sharedByPtr = SearchobjByID(temp);
					PostInfo[i]->SetShared(sharedByPtr);
					sharedByPtr->AddposttoTimeline(PostInfo[i]);
				}
				else if (temp[0] == 'p')
				{
					char* ID = Helper::GetStringFromBuffer(temp);
					Object* sharedByPtr = SearchobjByID(temp);
					PostInfo[i]->SetShared(sharedByPtr);
					sharedByPtr->AddposttoTimeline(PostInfo[i]);
				}



				Read >> temp;

				while (temp[0] != '-')
				{
					if (temp[0] == 'u')
					{
						char* ID = Helper::GetStringFromBuffer(temp);
						Object* likedByPtr = SearchobjByID(temp);
						PostInfo[i]->SetLiked(likedByPtr);
						Read >> temp;

					}
					else if (temp[0] == 'p')
					{
						char* ID = Helper::GetStringFromBuffer(temp);
						Object* likedByPtr = SearchobjByID(temp);
						PostInfo[i]->SetLiked(likedByPtr);
						Read >> temp;
					}
				}
				i++;
			}
			Read.close();
		}
		else
		{
			cout << "Post File was not Properly Opened" << endl;
		}

	}

	void LoadComments(ifstream& Read)
	{
		Read.open("Comments.txt");
		if (Read.is_open())
		{
			Post* Postid = NULL;
			Object* Commentedby = NULL;

			char temp[100] = { '\0' };
			Read >> Comments::TotalComments;
			Comments** CommentList = new Comments * [Comments::TotalComments];
			int i = 0;
			while (!Read.eof() && i < Comments::TotalComments)
			{
				CommentList[i] = new Comments;
				CommentList[i]->ReadDataFromCommentfile(Read);
				cout << "Comment" << i << endl;
				Read >> temp;

				Postid = SearchpostbyID(temp);

				for (int i = 0; i < 100; i++)
					temp[i] = '\0';

				Read >> temp;
				Commentedby = SearchobjByID(temp);

				CommentList[i]->AddCommentator(Commentedby);

				CommentList[i]->Loadtxt(Read);

				Postid->Addcomment(CommentList[i]);

				i++;

			}
			Read.close();
		}
		else
		{
			cout << "Cooments File was not Properly Opened " << endl;
		}
	}


	void LoadUsers(ifstream& Read)
	{
		Read.open("friendslist.txt");
		if (Read.is_open())
		{
			Read >> Users::TotalUsers;
			UserInfo = new Users * [Users::TotalUsers];
			int i = 0;
			while (!Read.eof() && i < Users::TotalUsers)// 2nd Condition is for cases when it is still reading after end of file
			{
				cout << "User" << i << endl;
				UserInfo[i] = new Users;
				UserInfo[i]->ReadDataFromUserFile(Read, PageInfo, Pages::TotalPages, UserInfo[i]);
				i++;
			}
			Users::SetFriends(UserInfo, Users::TotalUsers);

			Read.close();
		}
		else
		{
			cout << "User File was not properly opened" << endl;
		}
	}

	Pages* SearchPagesByID(Pages** P, char* SearchPage)
	{
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				char* UID = P[j][i].GetPageID();
				if (Helper::CompareString(UID, SearchPage))
				{
					return P[j];
				}
			}
		}
		cout << "You Have Entered Wrong ID" << endl;
		return NULL;
	}

	Users* SearchUserByID(Users** Users, char* SearchUser)  //This Function Searches Given ID
	{
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				char* UID = Users[j][i].GetUserID();
				if (Helper::CompareString(UID, SearchUser))
				{
					return Users[j];
				}
			}
		}
		cout << "You Have Entered Wrong ID" << endl;
		return NULL;
	}

	void Run()
	{
		char temp[10] = { 'u','7','\0' };
		cout << "\t\t\t\t\tCommand:\tSet current System Date  ";
		Date::CurrentDate.PrintDate();

		cout << endl;
		cout << endl << endl;;
		cout << "Command:\tSet current user to " << temp << endl;

		CurrentUser = SearchUserByID(UserInfo, temp);
		if (CurrentUser != NULL)
		{
			cout << CurrentUser->GetUserFName() << " " << CurrentUser->GetUserLName() << "  Successfully set as Current User " << endl << endl;
			Helper::ShowLine();
			CurrentUser->ViewFriendList();
			cout << endl;
			Helper::ShowLine();
			CurrentUser->ViewLikedPages();
			cout << endl;

			Helper::ShowLine();
			cout << "Command : \tView Timeline\t" << endl;
			Helper::ShowLine();
			CurrentUser->viewTimeline();
			Helper::ShowLine();

			cout << "Command : \tView Home\t" << endl;
			CurrentUser->ViewHome();
			Helper::ShowLine();


			cout << "Command : View Liked List (post5)" << endl;
			Helper::ShowLine();
			char temp[] = { 'p','o','s','t','5','\0' };
			Post* temppost = SearchpostbyID(temp);
			if (temppost != NULL)
			{
				temppost->PrintPost();
				cout << endl;
				cout << endl;

				temppost->ViewLikedBy();
				CurrentUser->LikeAPost(temppost);
				temppost->ViewLikedBy();

				char temp2[] = { 'u','7' };
				Object* tempobj = SearchobjByID(temp2);
				temppost->Likepost(tempobj);

				char tempp[] = { 'p','1','\0' };
				Pages* ptr = SearchPagesByID(PageInfo, tempp);
				int index = Helper::returnIndex(tempp);
				ptr->Viewpage();

				cout << endl;
				Helper::ShowLine();
				char post2[] = { 'p','o','s','t','4','\0' };
				char* text = new char[50]{ "Good Luck for your Result (2)" };

				cout << "Command: \tPost Comment(" << post2 << ", " << text << ")\n";
				Post* PostCCC = SearchpostbyID(post2);
				PostCCC->AddNewComment(text, CurrentUser);
				cout << "Command: \tView Post(" << post2 << ")\n\n";
				PostCCC->PrintPost();


				Helper::ShowLine();
				cout << endl;
				char post3[6] = "post8";
				char* text2 = new char[50]{ "Thanks for the wishes" };
				cout << "Command: \tPost Comment(" << post3 << ", " << text2 << ")\n";
				Post* PostCCC2 = SearchpostbyID(post3);
				PostCCC2->AddNewComment(text2, CurrentUser);
				cout << "Command: \tView Post(" << post3 << ")\n\n";
				PostCCC2->PrintPost();
				Helper::ShowLine();


				// Memories Viewing
				cout << "Command: \tSeeYourMemories()\n";
				CurrentUser->ViewYourMemories();
				Helper::ShowLine();


				char memoryPost[7] = "post9";
				Post* currentPost = SearchpostbyID(memoryPost);
				char shareText[70] = "Happy Birthday !";
				cout << "Command: \tShareMemory(" << memoryPost << ",\"" << shareText << "\")\n";
				CurrentUser->ShareMemory(shareText, currentPost);
				cout << "\nCommand: \tView timeline\n";
				CurrentUser->PrintName();
				cout << "-Timeline:\n\n";
				CurrentUser->viewTimeline();
				cout << "--------------------------------------------------------------------------------------\n";



			}
		}
	}
};
int main()
{
	{
		Helper::ShowTitle();
		Facebook fb;
		fb.LoadData();
		fb.Run();
	}
	cout << endl << endl << endl << endl;
	return 0;
}