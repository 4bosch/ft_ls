#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#include <stdio.h>

int	main(int ac,  char **av)
{
	struct stat buf;
	struct passwd *pw;
	struct group *grp;

	if (ac != 2)
		return (0);
	stat(av[1], &buf);
	printf("Nom: %s\nType: ", av[1]);
	if ((buf.st_mode & S_IFMT) == S_IFSOCK)
		printf("Socket\n");
	else if ((buf.st_mode & S_IFMT) == S_IFLNK)
		printf("Link\n");
	else if ((buf.st_mode & S_IFMT) == S_IFREG)
		printf("File\n");
	else if ((buf.st_mode & S_IFMT) == S_IFBLK)
		printf("Block device\n");
	else if ((buf.st_mode & S_IFMT) == S_IFDIR)
		printf("Directory\n");
	else if ((buf.st_mode & S_IFMT) == S_IFCHR)
		printf("Character device\n");
	else
		printf("FIFO/pipe\n");
	printf("Modes: ");
	printf((S_ISDIR(buf.st_mode)) ? "d" : "-");
    printf((buf.st_mode & S_IRUSR) ? "r" : "-");
    printf((buf.st_mode & S_IWUSR) ? "w" : "-");
    printf((buf.st_mode & S_IXUSR) ? "x" : "-");
    printf((buf.st_mode & S_IRGRP) ? "r" : "-");
    printf((buf.st_mode & S_IWGRP) ? "w" : "-");
    printf((buf.st_mode & S_IXGRP) ? "x" : "-");
    printf((buf.st_mode & S_IROTH) ? "r" : "-");
    printf((buf.st_mode & S_IWOTH) ? "w" : "-");
    printf((buf.st_mode & S_IXOTH) ? "x\n" : "-\n");
	printf("Nombre de liens: %d\n", buf.st_nlink);
	pw = getpwuid(buf.st_uid);
	if (pw != 0)
		printf("Proprietaire: %s\n", pw->pw_name);
	grp = getgrgid(buf.st_gid);
	if (grp != 0)
		printf("Groupe: %s\n", grp->gr_name);
	printf("Taille: %d octets\n", buf.st_size);
	printf("Date de derniere modification: %s\n", ctime(&buf.st_mtim));
	return (0);
}
