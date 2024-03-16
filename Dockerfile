# Use a base image with httpd pre-installed
FROM httpd:latest

# Install required dependencies for emscripten
RUN apt-get update && apt-get install -y \
    git \
    cmake \
    python3 \
    nodejs \
    npm \
    neovim \
    && rm -rf /var/lib/apt/lists/*

# Clone Emscripten repository
RUN git clone https://github.com/emscripten-core/emsdk.git

# Install Emscripten
RUN cd emsdk && \
    ./emsdk install latest && \
    ./emsdk activate latest && \
    echo 'source /usr/local/apache2/emsdk/emsdk_env.sh' >> /root/.bashrc

RUN apt install neovim