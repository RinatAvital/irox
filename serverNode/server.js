
const app = express()

let arrMessages = []


app.set('view engine', 'ejs')
app.use(express.urlencoded({ extended: true }))
app.use(express.json())

app.listen('3030', _ => console.log('server is listening in http://n'))

app.get('/', (req, res) => {
    res.send('server works')
})

app.post('/sendMessage', (req, res) => {
    let buffer = req.body.message

    let parsedMessage = buffer
    console.log( req.body);
    res.send( req.body.message)
    // res.send(450)

    // arrMessages.push(parsedMessage)
    // res.render('index', arrMessages)
})






