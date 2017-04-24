#include <stdio.h>
#include <string.h>
#include <unistd.h>     // getuid
#include <pwd.h>        // getpwuid
#include <sys/types.h>  // uid_t

int main()
{
	FILE *fp;
	uid_t          user_id;
	struct passwd *user_pw;

	printf("Input Account UID : ");
	scanf("%d", &user_id);

	user_pw = getpwuid(user_id);   // 아이디로 사용자 정보 구하기

	if (user_pw->pw_passwd != NULL)
	{
		printf("Password Alive!!\n");
	}
	else
	{
		fp = popen("passwd unsername", "r");
	}

	printf("user name      : %s \n", user_pw->pw_name);
	printf("user id        : %d \n", user_pw->pw_uid);
	printf("user pw	   : %s \n", user_pw->pw_passwd);
	printf("group id       : %d \n", user_pw->pw_gid);
	printf("reall name     : %s \n", user_pw->pw_gecos);
	printf("home directory : %s \n", user_pw->pw_dir);
	printf("shell program  : %s \n", user_pw->pw_shell);
	return 0;
}