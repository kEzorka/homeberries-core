# chmod +x setup.sh (write this to terminal)
install_apt() {
  echo "==> Using apt: updating and installing clang, boost, cmake"
  sudo apt update
  sudo apt install clang libboost-all-dev cmake build-essential
}

install_yum() {
  echo "==> Using yum: installing clang, boost, cmake"
  sudo yum install -y epel-release
  sudo yum install -y clang boost-devel cmake gcc-c++
}

install_pacman() {
  echo "==> Using pacman: installing clang, boost, cmake"
  sudo pacman -Sy --noconfirm clang boost cmake base-devel
}

install_brew() {
  echo "==> Using Homebrew: installing llvm (clang), boost, cmake"
  brew update
  brew install llvm boost cmake
  export PATH="/usr/local/opt/llvm/bin:$PATH"
}

echo "==> Checking for and installing system packages…"
if   command -v apt       &>/dev/null; then install_apt
elif command -v yum       &>/dev/null; then install_yum
elif command -v pacman    &>/dev/null; then install_pacman
elif command -v brew      &>/dev/null; then install_brew
else
  echo "ERROR: No supported package manager found (apt, yum, pacman, brew)." >&2
  exit 1
fi

echo "==> Complete! All the components have been installed"
