# fpbass

Fpbass, pronounced "Ef-pEE-bAYs", short for "Fourier-parametrized bytewise audio synthesis software", is an attempt at a low-level digital audio workstation (DAW) without any graphical interface. The idea is to compose experimental electronic music quickly from the terminal, as an alternative to GUI-based DAWs.

WAV files are to be generated from configuration files that supply note information. Every note is parametrized by its Fourier decomposition.

So far no serious applications are planned---Fpbass is a toy project that shall explore the possibilities of command-line based audio synthesis.

## History

The first codes date back to late 2016, in the context of the noise music project [Struct](http://struct.square7.ch/).

In 2020, the work on a first publishable version began.

## Usage

In the current simplistic implementation, you have to edit both the data string and the file size in `wavgen.cpp`. Then compile and run:

    $ make
    $ ./wavgen.o

The `output.wav` is then generated.

Note that this is just a proof of concept. The more user-friendly design of Fpbass with configuration files will follow.

## Contribute

Now that this project is public, you can in principle contribute to it. Small stuff can be done at any time. I will name larger challenges under "Issues".

Please look at [CONTRIBUTE.md](CONTRIBUTE.md) to see how and where one can contribute.
