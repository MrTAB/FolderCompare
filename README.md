# FolderCompare
A small utility that compares two similar folders to find unique files.

Developed using TDM-2 mingw32 4.4.1 (just pre C++11) in Code::Blocks 10.05

Built for a specific purpose during game development to assist in constructing a matched pair of texture atlases -one full colour, the other for alpha blending- out of folders of individual images. Most of the alpha blend images were auto-generated as simple masks using another in house utility, while some were unique, and added to an exemption list. The alpha blend atlas has to match the full colour one exactly, so there can be no discrepancy on the file list going into each atlas - one less or more file and the generation time is wasted. This utility prevents that wasted time and alerts the developer to any discrepancy between the folders, and thus any changes required to the exemption list.
