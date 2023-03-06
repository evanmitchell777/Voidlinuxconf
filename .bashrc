# .bashrc

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
alias get='sudo xbps-install'
alias remove='sudo xbps-remove'
alias update='sudo xbps-install -Su'
alias off='sudo shutdown -h now'
alias net='sudo NetworkManager'

PS1='[\u@\h \W]\$ '
