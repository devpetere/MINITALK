# Minitalk

## Description
**Minitalk** est un projet visant à implémenter un système de communication entre un serveur et un client en utilisant les signaux UNIX (`SIGUSR1` et `SIGUSR2`). Ce projet met en avant la gestion des processus et la communication interprocessus (IPC).

---

## Fonctionnalités
- Communication entre un serveur et un client via signaux.
- Conversion des messages en binaire pour leur transmission.
- Affichage des messages reçus sur le serveur.
- Gestion robuste des erreurs (PID invalide, signaux perdus, etc.).

---

## Utilisation
### 1. Cloner le projet
```bash
git clone git@github.com:herirand/MINITALK.git
cd minitalk
```

### 2. Compilation
```bash
make
```

### 3. Exécution
#### Lancer le serveur :
```bash
./server
```
#### Envoyer un message avec le client :
```bash
./client <PID_du_serveur> "<message>"
```

Exemple :
```bash
./client 12345 "Hello, World!"
```

---

## Règles du projet
- Utilisation uniquement des signaux `SIGUSR1` et `SIGUSR2`.
- Gestion des erreurs (PID incorrect, signaux interrompus, etc.).
- Respect des normes de codage 42 (Norminette).

---

## Bonus
- Support des messages longs.
- Mesure du temps de transmission des messages.
- Gestion simultanée de plusieurs clients.

---

## Concepts explorés
- Signaux UNIX (`kill`, `sigaction`).
- Communication entre processus.
- Conversion binaire pour transfert de données.
- Gestion d'erreurs et robustesse.

---

## Exemple de démonstration
1. Lancer le serveur :
   ```bash
   ./server
   ```
   Sortie :
   ```bash
   Server PID: 12345
   ```

2. Envoyer un message avec le client :
   ```bash
   ./client 12345 "Hello, World!"
   ```
   Sortie sur le serveur :
   ```bash
   Message reçu : Hello, World!
   ```

