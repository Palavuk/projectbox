#pragma once
#include <iostream>

template <class stream>
class stream_guard{
    private:
	    stream& _stream;
	    std::ios::fmtflags flags_lock;
	    char fill_lock;
        std::ios_base::iostate exceptions_lock;
    public:
        stream_guard(stream& str) : _stream(str)
	    {
	    	flags_lock = _stream.flags();
	    	fill_lock = _stream.fill();
            exceptions_lock = _stream.exceptions();
	    };
    
        ~stream_guard(){
            stream.flags(stream_flags);
            stream.fill(stream_fill);
            stream.exceptions(exceptions_lock);
        };
}      