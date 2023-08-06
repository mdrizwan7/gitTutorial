git tutorial

#setting user name
```
$ git config --global user.name "username"
```

#setting email
```
$ git config --global user.email "useremail@gmail.com"
```

#To see user info
```
$ git config user.name
$ git config user.email
```

#How to check status for any folder/directory
$ git status

//Don't run $ git init if your git repo is already present otherwise 
//new git repo will replace your repository
#Making new repository
$ git init

#adding to staging area
$ git add <file>
$ git add --a 	//this will add all files to staging area
$ git add .	//this will add all files to staging area

#To commit files from staging area to git repository with commit message
$ git commit -m "m_e_s_s_a_g_e"

#To remove or delete a git repository
$ rm -rf .git

#To clone a remote git repository from GitHub/Any
$ git clone <url>

#To paste in git bash terminal shortcut : { Shift+Insert }

#You can view all of your settings and where they are using:
$ git config --list --show-origin
//To view only settings
$ git config --list

#git help commands
$ git <command> -h
//for ex:
$ git config -h || $ git config -help	// a quick refresher 
$ git config --help  // open a manual page for that command

#if you need to ignore some files from getting tracked
//1. create .gitignore
//2. add file name which you want to stop tracking with extension in .gitignore

#if you need to ignore files with particular extension
//1. add *.extension in .gitignore

#if directory is EMPTY git won't track it
#if you need to ignore directory/folder from tracking
//1. add directory in .gitignore
// ex: dir/
#if you want only your outer directory named dir to be untracked
// write like this : /dir/

#if you want to compare files in working directory and staging area
$ git diff

#if you want to compare files between staging area and last commit
$ git diff --staged

#if you want to completely skip the staging area
$ git commit -a -m "m_e_s_s_a_g_e"
//this will skip the staging area and directly commit
//this will not commit untracked files

#if a file is already getting tracked and now you do not wish to track it
//1. add <file_name> to .gitignore
//2. now you have to explicitly tell git to not track <file_name>
$ git rm --cached <file_name>

#To see complete commit history with Author name,email,message
$ git log
//if you also want to see changes/diff due to commit
$ git log -p
//if you only want top 3 commits
$ git log -p -3
//if you want to see commit history with short details
$ git log --stat
//if you want to see commit history in one line per commit
$ git log --pretty=oneline
//if you want only Author name,email and commit message
$ git log--pretty=short
//if you want only Author name,email Commit name,email and commit message
$git log --pretty=full
//if you want to filter commits according to time
$ git log --since=30.minutes
$ git log --since=2.hours
$ git log --since=2.days
$ git log --since=3.weeks
$ git log --since=5.months
$ git log --since=1.years
//if you want only abbreviated commit hash and author name
//can customise multiple options are available
//refer git-scm.com
$ git log --pretty=format:"%h %an"

#if you want to merge your commit with most recent commit and
//change commit message
$ git commit --amend
//it will open in vim where you can edit commit message

#To unstage/remove files from staging area
$ git rm --staged <file>

#----------refer documentation------------
$ git rm --cached <file>

#if you have changed/deleted file in working directory and want to get
-//last commit variant of file
//Remember if variant of file is present in staging area then staging
-//area file variant will get replaced with working directory file
$ git checkout -- <file>

#if you want to match your working directory with your last commit
$ git checkout -f
//Remember this will clean files from staging area,
-//So if you have files in your staging area that you want to consider
-//first commit them then only run this command

#Working with remote repository
$ git remote add origin git@github.com:----------

//generate ssh key refer : generate ssh key github
//add ssh key to github profile
//from 13/08/2021 password authentication has been disabled
//so you have to generate a personal access token
**********************************************************************
**********************************************************************
**********************************************************************
/*
* From 2021-08-13, GitHub is no longer accepting account passwords
when authenticating Git operations. You need to add a
PAT (Personal Access Token) instead, and you can follow the
below method to add a PAT on your system.

*Create Personal Access Token on GitHub
From your GitHub account, go to Settings → Developer Settings → Personal Access Token → Generate New Token (Give your password) → Fillup the form → click Generate token → Copy the generated Token, it will be something like ghp_sFhFsSHhTzMDreGRLjmks4Tzuzgthdvfsrta

Now follow the below method based on your machine:

For Windows OS ⤴
Go to Credential Manager from Control Panel → Windows Credentials → find git:https://github.com → Edit → On Password replace with with your GitHub Personal Access Token → You are Done

If you don’t find git:https://github.com → Click on Add a generic credential → Internet address will be git:https://github.com and you need to type in your username and password will be your GitHub Personal Access Token → Click Ok and you are done
*/
**********************************************************************
**********************************************************************
**********************************************************************

#To push code
$ git push -u origin main

#Creating alias in git
$ git config --global alias.ci commit
$ git config --global alias.st status
$ git config --global alias.unstage 'restore --staged --'	//whatever file name i will give it will be placed at location --
$ git config --global alias.last 'log -p -1'
//local alias only till terminal is open
$ alias ci=commit
//removing alias
$ git config --global --unset alias.NAME

#Creating Branches
$ git checkout -b develop
//this will create new branch named develop and will take you to develop branch
#To see all branches
$ git branch	//will highlight working branch in GREEN
#To switch between branches
$ git switch BRANCH_NAME
$ git checkout BRANCH_NAME

#To merge branches
$ git merge BRANCH_NAME
//if there are no conflicts in your branches git will successfully merge
//otherwise merge conflict issue will be raised
#Please commit your changes or stash them before you switch branches.
**********************************************************************
Merge conflicts happen when you merge branches that have competing
commits, and Git needs your help to decide which changes to 
incorporate in the final merge.

Git can often resolve differences between branches and merge them
automatically.Usually,the changes are on different lines,or even in
different files, which makes the merge simple for computers to
understand. However, sometimes there are competing changes that Git
can't resolve without your help. Often, merge conflicts happen when
people make different changes to the same line of the same file,or
when one person edits a file and another person deletes the same file.
**********************************************************************

#To abort a merge in case of merge conflict
$ git merge --abort

#To resolve merge conflicts open vs code and do as per requirement.
or
//you can also resolve merge conflict in git using vimdiff
$ git mergetool
//it will open vim and highlight differences
**********************************************************************
**********************************************************************
Open Git Bash.
Navigate into the local Git repository that has the merge conflict.

$ cd REPOSITORY-NAME
Generate a list of the files affected by the merge conflict.
In this example, the file styleguide.md has a merge conflict.

$ git status
> # On branch branch-b
> # You have unmerged paths.
> #   (fix conflicts and run "git commit")
> #
> # Unmerged paths:
> #   (use "git add <file>..." to mark resolution)
> #
> # both modified:      styleguide.md
> #
> no changes added to commit (use "git add" and/or "git commit -a")

Open your favourite text editor, such as Visual Studio Code, and
navigate to the file that has merge conflicts.

To see the beginning of the merge conflict in your file, search the
file for the conflict marker <<<<<<<. When you open the file in your
text editor, you'll see the changes from the HEAD or base branch after
the line <<<<<<< HEAD. Next, you'll see =======, which divides your
changes from the changes in the other branch, followed by >>>>>>>BRANCH-NAME.
In this example, one person wrote "open an issue" in the base or HEAD
branch and another person wrote "ask your question in IRC" in the
compare branch or branch-a.

<<<<<<< HEAD
open an issue
=======
ask your question in IRC.
>>>>>>> branch-a

Decide if you want to keep only your branch's changes, keep only the
other branch's changes, or make a brand new change, which may incorporate
changes from both branches. Delete the conflict markers <<<<<<<, 
=======, >>>>>>> and make the changes you want in the final merge.
In this example, both changes are incorporated into the final merge:

Add or stage your changes.
$ git add .
Commit your changes with a comment.
$ git commit -m "Resolved merge conflict by incorporating both suggestions."

----------------------------------------------------------------------
#to resolve merge conflicts related to remote repo
refer : https://www.simplilearn.com/tutorials/git-tutorial/merge-conflicts-in-git

**********************************************************************
**********************************************************************
#To see last commit of each branch
$ git branch -v

#To see all branch that you have already merged
$ git branch --merged

#To see all branch that you have not merged yet
$ git branch --no-merged
//it will show nothing if other branch have no change wrt master branch

#To delete a branch
$ git branch -d BRANCH_NAME
//if you have not merged, it will give error
//you can delete by running command
$ git branch -D BRANCH_NAME
or
$ git branch -d BRANCH_NAME --force

#git stash : saving your untracked / modified files if you wanna change branch
**********************************************************************
The git stash command takes your modified tracked files and saves it
on a pile of incomplete changes that you can reapply at any time. To
go back to work, you can use the stash pop.

The git stash command will help a developer switch branches to work on
something else without committing incomplete work.

# Store current work with 
$ git stash -u

# Bring stashed work back to the working directory
$ git stash pop
**********************************************************************

#Deleting branch on remote repo
$ git push -d <remote> BRANCH_NAME
ex : $ git push -d origin develop


#To revert back to older version of a commit
$ git checkout <commit_hash> <file_name>
