#FROM geant4/geant4

# Geant4:
FROM koichimurakamik6/geant4-runtime

# Root:
#FROM rootproject/root

# setting this variable that geant4 can't find
ENV LD_LIBRARY_PATH=/opt/geant4/lib:$LD_LIBRARY_PATH

WORKDIR /test_calorimeter

COPY . .

RUN mkdir docker_build && \
  cd docker_build && \
  cmake .. && \
  make

ENTRYPOINT [ "/bin/bash" ]