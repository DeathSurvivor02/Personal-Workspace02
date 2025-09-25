function MainRouter() {
    return (
        <div>
            <Routes>
                <Route path="/" element={<Home />} />
                <Route path="/about" element={<About />} />
                <Route path="/projects" element={< Projects/>} />
                <Route path="*" element={<NotFound />} />
            </Routes>
        </div>
    );
}

export default MainRouter;