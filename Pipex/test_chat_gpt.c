#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Vérifiez qu'il y a exactement 4 arguments
  if (argc != 5) {
    fprintf(stderr, "Usage: ./pipex infile \"commande 1\" \"commande 2\" outfile\n");
    return 1;
  }

  // Ouvrez les fichiers d'entrée et de sortie
  FILE *infile = fopen(argv[1], "r");
  FILE *outfile = fopen(argv[4], "w");
  if (!infile || !outfile) {
    perror("Erreur lors de l'ouverture des fichiers");
    return 1;
  }

  // Créez un pipe pour la communication entre les deux commandes
  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("Erreur lors de la création du pipe");
    return 1;
  }

  // Créez un processus fils pour exécuter la première commande
  pid_t pid = fork();
  if (pid == 0) {
    // Dans le processus fils :

    // Redirigez l'entrée standard vers le fichier d'entrée
    if (dup2(fileno(infile), STDIN_FILENO) == -1) {
      perror("Erreur lors de la redirection de l'entrée standard");
      return 1;
    }

    // Redirigez la sortie standard vers le pipe
    if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
      perror("Erreur lors de la redirection de la sortie standard");
      return 1;
    }

    // Fermez les descripteurs de fichiers inutiles
    fclose(infile);
    close(pipefd[0]);
    close(pipefd[1]);

    // Préparez les arguments pour execve
    char *const cmd1_argv[] = {"/bin/sh", "-c", argv[2], NULL};

    // Exécutez la première commande
    execve("/bin/sh", cmd1_argv, NULL);

    // Si execve renvoie, c'est qu'il y a eu une erreur
    perror("Erreur lors de l'exécution de la première commande");
    return 1;
  } else if (pid < 0) {
    // Si fork a échoué, affichez une erreur
    perror("Erreur lors de la création du processus fils");
    return 1;
  }

  // Créez un second processus fils pour exécuter la seconde commande
  pid_t pid2 = fork();
  if (pid2 == 0) {
    // Dans le second processus fils :

    // Redirigez l'entrée standard vers le pipe
    if (dup2(pipefd[0], STDIN_FILENO) == -1) {
      perror("Erreur lors de la redirection de l'entrée standard");
      return 1;
    }

    // Redirigez la sortie standard vers le fichier de sortie
    if (dup2(fileno(outfile), STDOUT_FILENO) == -1) {
      perror("Erreur lors de la redirection de la sortie standard");
      return 1;
    }

    // Fermez les descripteurs de fichiers inutiles
    fclose(outfile);
    close(pipefd[0]);
    close(pipefd[1]);

    // Préparez les arguments pour execve
    char *const cmd2_argv[] = {"/bin/sh", "-c", argv[3], NULL};

    // Exécutez la seconde commande
    execve("/bin/sh", cmd2_argv, NULL);

    // Si execve renvoie, c'est qu'il y a eu une erreur
    perror("Erreur lors de l'exécution de la seconde commande");
    return 1;
  } else if (pid2 < 0) {
    // Si fork a échoué, affichez une erreur
    perror("Erreur lors de la création du second processus fils");
    return 1;
  }

  // Fermez les descripteurs de fichiers et le pipe dans le processus principal
  fclose(infile);
  fclose(outfile);
  close(pipefd[0]);
  close(pipefd[1]);

  // Attendez la fin des deux processus fils
  waitpid(pid, NULL, 0);
  waitpid(pid2, NULL, 0);

  return 0;
}